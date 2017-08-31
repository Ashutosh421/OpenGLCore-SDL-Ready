#pragma once
#include "../Light.h"

namespace AREngine {

	class AreaLight : public Light
	{
	private:

	public:
		AreaLight();
		~AreaLight();
		
		void update() override;
	};

}


