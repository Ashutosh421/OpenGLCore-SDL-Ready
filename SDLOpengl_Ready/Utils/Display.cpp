#include "Display.h"

namespace AREngine {

	int Display::WIDTH = 1024;
	int Display::HEIGHT = 768;
	Display* Display::instance_H = nullptr;

	void Display::Launch(std::string title, short width, short height) {
		Display::WIDTH = width;
		Display::HEIGHT = height;
		m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Display::WIDTH, Display::HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
		if (m_window == NULL)
		{
			std::cout << "Coudln't create the SDL Window " << SDL_GetError() << std::endl;
		}
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		m_glContext = SDL_GL_CreateContext(this->m_window);
		if (m_glContext == NULL)
		{
			std::cout << "Couldn't create the Gl Context " << SDL_GetError() << std::endl;
			return;
		}
		GLenum glInit = glewInit();
		if (glInit != GLEW_OK)
		{
			std::cout << "GLEW cloudn't be initialized " << glewGetErrorString(glInit) << std::endl;
			return;
		}
		else
		{
			std::cout << "Glew Initialized successfully " << glGetString(GL_VERSION) << std::endl;
		}
		//glViewport( 0 , 0 , Display::WIDTH , Display::HEIGHT);
		glEnable(GL_DEPTH_TEST);
	}

	void Display::ResizeDisplay(short width ,  short height) 
	{
		Display::WIDTH = width;
		Display::HEIGHT = height;
		glViewport( 0 , 0 , Display::WIDTH , Display::HEIGHT);
	}

	void Display::Update()
	{
		SDL_GL_SwapWindow(this->m_window); //SDL Window Double Buffering
	}

	void Display::Clear() 
	{
		glClearColor( 0.2f , 0.2f, 0.2f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	Display* Display::instance() {
		if (instance_H == nullptr)
		{
			instance_H = new Display();
		}
		return instance_H;
	}

	void Display::Dispose() 
	{
		delete instance_H;
	}

	Display::~Display()
	{	
		SDL_DestroyWindow(m_window);
	}
}