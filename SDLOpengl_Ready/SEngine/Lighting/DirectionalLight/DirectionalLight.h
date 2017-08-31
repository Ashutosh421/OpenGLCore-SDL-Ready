#pragma once
#include "../Light.h"

namespace AREngine {

	class DirectionalLight : public Light
	{
	private:

	public:
		DirectionalLight();
		~DirectionalLight();
		void update() override;
	};

}



