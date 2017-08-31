#pragma once
#include "../Light.h"

namespace AREngine {

	class SpotLight : public Light
	{
	private:

	public:
		SpotLight();
		~SpotLight();
		void update() override; 
	};
}



