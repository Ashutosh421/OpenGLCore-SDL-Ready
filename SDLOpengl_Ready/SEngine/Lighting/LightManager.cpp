#include "LightManager.h"

namespace AREngine {

	LightManager* LightManager::instance_H = nullptr;

	LightManager::LightManager()
	{

	}

	LightManager::~LightManager()
	{
		auto it = sceneLights.begin();
		for (it = sceneLights.begin(); it < sceneLights.end(); it++)
		{
			delete *it;
		}
	}

	Light* LightManager::Instantiate(LightType lightType) {
		if (lightType == LightType::DIRECTIONAL_LIGHT)
		{
			Light* newLight = new DirectionalLight();
			LightManager::instance()->Add(newLight);
			return newLight;
		}
		else if (lightType == LightType::POINT_LIGHT)
		{
			Light* newLight = new PointLight();
			LightManager::instance()->Add(newLight);
			return newLight;
		}
		else if (lightType == LightType::SPOT_LIGHT)
		{
			Light* newLight = new SpotLight();
			LightManager::instance()->Add(newLight);
			return newLight;
		}
		else if (lightType == LightType::AREA_LIGHT)
		{
			Light* newLight = new AreaLight();
			LightManager::instance()->Add(newLight);
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

	void LightManager::Add(Light* light) {
		sceneLights.push_back(light);
	}

	void LightManager::dispose()
	{
		delete instance_H;
	}
}


