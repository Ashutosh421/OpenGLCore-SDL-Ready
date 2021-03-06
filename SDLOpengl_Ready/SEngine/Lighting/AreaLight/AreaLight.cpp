#include "AreaLight.h"

namespace AREngine
{
	AreaLight::AreaLight()
	{

	}

	void AreaLight::update() {
		this->shader->BindShader();
		this->shader->SetModelMatrix(this->transform->getModelMatrix());
		if (this->viewCamera != nullptr)
		{
			this->shader->SetViewMatrix(this->viewCamera->getViewMatrix());
			this->shader->SetProjectionMatrix(this->viewCamera->getProjectionMatrix());
		}
		this->mesh->Draw();
		this->shader->UnbindShader();
	}

	AreaLight::~AreaLight()
	{

	}
}

