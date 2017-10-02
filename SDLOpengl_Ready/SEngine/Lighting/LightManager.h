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
		uint16_t pointLightsCount = 0;
		uint16_t areaLightsCount = 0;
		uint16_t spotLightsCount = 0;
		uint16_t directionalLightsCount = 0;

	public:
		std::vector<Light*> pointLights;
		std::vector<Light*> directionalLights;
		std::vector<Light*> spotLights;
		std::vector<Light*> areaLights;
		static Light* Instantiate(LightType);
		static LightManager* instance();
		void Add(Light*, const LightType&);
		void Clean();
		inline uint16_t NumberOfPointLights()
		{
			return pointLightsCount;
		}
		inline uint16_t NumberOfDirectionalLights() 
		{
			return directionalLightsCount;
		}
		inline uint16_t NumberOfSpotLights()
		{
			return spotLightsCount;
		}
		inline uint16_t NumberOfAreaLights()
		{
			return areaLightsCount;
		}
		inline uint16_t NumberOfLights()
		{
			return (pointLightsCount + directionalLightsCount + spotLightsCount + areaLightsCount);
		}
	};

}


