#pragma once
#include "../Light.h"

namespace AREngine {

	class PointLight : public Light
	{
	private:

	public:
		PointLight();
		~PointLight();
		void update() override;
	};

}


