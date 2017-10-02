#include "LightManager.h"

namespace AREngine {

	LightManager* LightManager::instance_H = nullptr;

	LightManager::LightManager()
	{

	}

	LightManager::~LightManager()
	{
		/*auto it = sceneLights.begin();
		for (it = sceneLights.begin(); it < sceneLights.end(); it++)
		{
			delete *it;
		}*/
		std::vector<Light*>::iterator it;
		it = pointLights.begin();
		for (it = pointLights.begin() ; it != pointLights.end() ; it++)
		{
			delete *it;
		}
		it = directionalLights.begin();
		for ( it = directionalLights.begin() ; it < directionalLights.end() ; it++)
		{
			delete *it;
		}
		it = areaLights.begin();
		for ( it = areaLights.begin() ; it < areaLights.end(); it++ )
		{
			delete *it;
		}
	}

	Light* LightManager::Instantiate(LightType lightType) {
		if (lightType == LightType::DIRECTIONAL_LIGHT)
		{
			Light* newLight = new DirectionalLight();
			LightManager::instance()->Add(newLight , lightType);
			instance_H->directionalLightsCount++;
			return newLight;
		}
		else if (lightType == LightType::POINT_LIGHT)
		{
			Light* newLight = new PointLight();
			LightManager::instance()->Add(newLight, lightType);
			instance_H->pointLightsCount++;
			return newLight;
		}
		else if (lightType == LightType::SPOT_LIGHT)
		{
			Light* newLight = new SpotLight();
			LightManager::instance()->Add(newLight, lightType);
			instance_H->spotLightsCount++;
			return newLight;
		}
		else if (lightType == LightType::AREA_LIGHT)
		{
			Light* newLight = new AreaLight();
			LightManager::instance()->Add(newLight, lightType);
			instance_H->areaLightsCount++;
			return newLight;
		}
		return nullptr;
	}

	LightManager* LightManager::instance()
	{
		if (instance_H == nullptr)
		{
			instance_H = new LightManager();
		}
		return instance_H;
	}

	void LightManager::Add(Light* light, const LightType& lightType) {
		if (lightType == LightType::POINT_LIGHT)
		{
			pointLights.emplace_back(light);
		}
		if (lightType == LightType::SPOT_LIGHT)
		{
			spotLights.emplace_back(light);
		}
		if (lightType == LightType::AREA_LIGHT)
		{
			areaLights.emplace_back(light);
		}
		if (lightType == LightType::DIRECTIONAL_LIGHT)
		{
			directionalLights.emplace_back(light);
		}
	}

	void LightManager::Clean()
	{
		delete instance_H;
	}
	
}


