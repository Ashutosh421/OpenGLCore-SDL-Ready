#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include "../Utils/Input/Input.h"
#include "../Utils/Display.h"
#include "../SEngine/Time/Time.h"

namespace AREngine {
	enum EngineStatus
	{
		RUNNING,
		CLOSED
	};

	class Engine
	{
	private:
		SDL_Event sdlEvent;
		static Engine* instance_H;
		Engine() = default;
		~Engine() = default;

	public:

		static EngineStatus engineStatus;
		void Init();
		static Engine* instance();
		void Close();
		void PollEvents();
	};
}

