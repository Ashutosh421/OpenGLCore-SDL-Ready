#include "Transform.h"

namespace AREngine {

	Transform::Transform()
	{
		position = Vector3(0 , 0 , 0 );
		eulerAngles = Vector3(0, 0, 0);
		scale = Vector3(1, 1, 1);
		
		this->transaltionMatrix = glm::mat4(1.0f);
		this->rotationMatrix = glm::mat4(1.0f);

		this->rotateXMat = glm::mat4(1.0f);
		this->rotateYMat = glm::mat4(1.0f);
		this->rotateZMat = glm::mat4(1.0f);
		rotationMatrix = rotateZMat * rotateYMat * rotateXMat;

		this->scaleMatrix = glm::mat4(1.0f);
	
		modelMatrix = transaltionMatrix * rotationMatrix * scaleMatrix;
	}

	void Transform::Translate(const Vector3& direction) {
		this->position += direction;
	}

	void Transform::Rotate(const Vector3& axis) {
		this->eulerAngles += axis;
	}

	void Transform::Scale(const Vector3& scale) {
		this->scale += scale;
	}

	glm::mat4 Transform::getModelMatrix() 
	{	
		transaltionMatrix = glm::translate(glm::mat4(1.0f), position.toGLM());

		rotateXMat = glm::rotate(glm::mat4(1.0f), glm::radians(eulerAngles.x), glm::vec3(1, 0, 0));
		rotateYMat = glm::rotate(glm::mat4(1.0f), glm::radians(eulerAngles.y), glm::vec3(0, 1, 0));
		rotateZMat = glm::rotate(glm::mat4(1.0f), glm::radians(eulerAngles.z), glm::vec3(0, 0, 1));

		rotationMatrix = rotateZMat * rotateYMat * rotateXMat;

		scaleMatrix = glm::scale(glm::mat4(1.0f), scale.toGLM());
		modelMatrix = transaltionMatrix * rotationMatrix * scaleMatrix;

		return modelMatrix;
	}

	Transform::~Transform()
	{

	}
}

