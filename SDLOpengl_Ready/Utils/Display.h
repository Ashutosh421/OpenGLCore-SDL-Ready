#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include <GL\glew.h>


namespace AREngine {
	class Display final
	{
	private:
		std::string m_title;
		static Display* instance_H;

	public:
		SDL_Window* m_window;
		SDL_GLContext m_glContext;
		static int WIDTH;
		static int HEIGHT;
		~Display();
		Display() = default;

	public:
		void Launch(std::string title, short width, short height);
		void Update();
		void Clear();
		void Dispose();
		void ResizeDisplay(short , short);
		static Display* instance();

		//Setters
		inline void SetTitle(std::string title) {
			this->m_title = title;
		}

		inline std::string GetTitle() {
			return this->m_title;
		}
	};
}

