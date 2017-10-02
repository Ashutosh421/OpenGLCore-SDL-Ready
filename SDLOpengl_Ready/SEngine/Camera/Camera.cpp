#include "Camera.h"

namespace AREngine {

	Camera::Camera()
	{
		transform = new Transform();
		transform->position = Vector3( 0 , 0 , 0);
		transform->eulerAngles = Vector3( 0 , 0 , 0);

		forward = Vector3( 0 , 0 , 1);
		up = Vector3( 0 , 1.0f , 0);
		
		viewMatrix = glm::lookAt(transform->position.toGLM(), forward.toGLM() , up.toGLM());
		projectionMatrix = glm::perspective(30.0f, (float)Display::WIDTH / Display::HEIGHT, 0.01f, 1000.0f);
	}

	glm::mat4 Camera::getViewMatrix() {
		lookATTarget = transform->position + forward;
		//lookATTarget = Vector3::zero;
		viewMatrix = glm::lookAt(transform->position.toGLM(), lookATTarget.toGLM(), up.toGLM());
		return viewMatrix;
	}

	glm::mat4 Camera::getProjectionMatrix() {
		return projectionMatrix;
	}

	void Camera::SetProjection(Camera::Projection projectionType) {
		this->projection = projectionType;
	}

	void Camera::update() 
	{
		//std::cout << "Camera Update Funct.ion " << std::endl;
		viewMatrix = glm::lookAt(transform->position.toGLM(), forward.toGLM(), up.toGLM());
		if (Input::IsKeyDown_Repeat(SDL_SCANCODE_E))
		{
			this->transform->position += Vector3(0, 1.0f, 0) * Time::deltaTime;
		}
		if (Input::IsKeyDown_Repeat(SDL_SCANCODE_Q))
		{
			this->transform->position += Vector3(0, -1.0f, 0) * Time::deltaTime;
		}
		if (Input::IsKeyDown_Repeat(SDL_SCANCODE_A))
		{
			this->transform->position += Vector3(-1.0f, 0, 0) * Time::deltaTime;
		}
		if (Input::IsKeyDown_Repeat(SDL_SCANCODE_D))
		{
			this->transform->position += Vector3(1.0f, 0, 0) * Time::deltaTime;
		}
		if (Input::IsKeyDown_Repeat(SDL_SCANCODE_W))
		{
			this->transform->position += Vector3(0, 0, 1.0f) * Time::deltaTime;
		}
		if (Input::IsKeyDown_Repeat(SDL_SCANCODE_S))
		{
			this->transform->position += Vector3(0, 0, -1.0f) * Time::deltaTime;
		}
	}

	void Camera::LookAT(const Vector3& target) {
		lookATTarget = target;
	}

	Camera::~Camera()
	{
	}
}


