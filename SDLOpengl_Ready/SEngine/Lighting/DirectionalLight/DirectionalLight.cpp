#include "DirectionalLight.h"

namespace AREngine 
{
	DirectionalLight::DirectionalLight()
	{
		this->direction = Vector3( 0 , 0 , 0 );
	}

	DirectionalLight::~DirectionalLight()
	{

	}

	void DirectionalLight::update() {
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
}


