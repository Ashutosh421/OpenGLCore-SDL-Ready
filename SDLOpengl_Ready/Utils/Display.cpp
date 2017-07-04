#include "Display.h"

namespace AREngine {
	Display::Display(std::string title, short width, short height) :m_title(title), m_width(width), m_height(height)
	{
		m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
		if (m_window == NULL)
		{
			std::cout << "Coudln't create the SDL Window " << SDL_GetError() << std::endl;
		}

		SDL_GL_SetAttribute(SDL_GL_RED_SIZE , 32);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE , 32);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER , 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION , 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK , SDL_GL_CONTEXT_PROFILE_CORE);

		m_glContext = SDL_GL_CreateContext(this->m_window);
		if (m_glContext == NULL)
		{
			std::cout << "Couldn't create the Gl Context " << SDL_GetError() <<  std::endl;
			return;
		}
		GLenum glInit = glewInit();
		if (glInit != GLEW_OK)
		{
			std::cout << "GLEW cloudn't be initialized " << glewGetErrorString(glInit) <<  std::endl;
			return;
		}
		else 
		{
			std::cout << "Glew Initialized successfully " << glGetString(GL_VERSION) << std::endl;
		}


#pragma region OLD_SHIT
		//m_Renderer = SDL_GetRenderer(m_window);
		/*if (m_Renderer == NULL)
		{
		std::cout << "SDL couldn't create the Renderer! " << "Creating the Renderer now.. ";
		m_Renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
		if (m_Renderer == NULL)
		{
		std::cout << "SDL couldn't create the Renderer! " << SDL_GetError();
		return;
		}
		else
		{
		std::cout << "SDL successfully created a Renderer " << std::endl;
		}
		}*/
#pragma endregion
	}

	void Display::Update()
	{

		SDL_GL_SwapWindow(this->m_window); //SDL Window Double Buffering
#pragma region OLD_SHIT
		//	SDL_RenderPresent(this->m_Renderer);
#pragma endregion
	}

	void Display::Clear() 
	{
		glClearColor( 0.0f , 0.0f, 0.0f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#pragma region OLD_SHIT
		//SDL_SetRenderDrawColor(this->m_Renderer, 125, 125, 255, 255);
		//SDL_RenderClear(this->m_Renderer);
#pragma endregion
	}

	Display::~Display()
	{

#pragma region OLD_SHIT
		//	SDL_DestroyRenderer(m_Renderer);
#pragma endregion
		SDL_DestroyWindow(m_window);
	}
}