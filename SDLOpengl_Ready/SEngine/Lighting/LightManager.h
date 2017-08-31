#pragma once
#include <vector>
#include "Light.h"

#include "DirectionalLight\DirectionalLight.h"
#include "AreaLight\AreaLight.h"
#include "PointLight\PointLight.h"
#include "SpotLight\SpotLight.h"

//Class that holds the Records of All the Light Currently Activate in the Scene
namespace AREngine {

	class LightManager
	{
	private:
		static LightManager* instance_H;
		LightManager();
		~LightManager();

	public:
		std::vector<Light*> sceneLights;
		static Light* Instantiate(LightType);
		static LightManager* instance();
		void Add(Light*);
		void dispose();
	};

}


