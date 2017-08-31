#pragma once
#include "..\..\Maths\Vector.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <GL\glew.h>

namespace AREngine {
	class Transform
	{
	private:
		glm::mat4 transaltionMatrix;

		glm::mat4 rotationMatrix;

		glm::mat4 rotateXMat;
		glm::mat4 rotateYMat;
		glm::mat4 rotateZMat;

		glm::mat4 scaleMatrix;

		glm::mat4 modelMatrix;
		
	public:
		Vector3 position;
		Vector3 eulerAngles;
		Vector3 scale;

		glm::mat4 getModelMatrix();

		void Translate(const Vector3&);
		void Rotate(const Vector3&);
		void Scale(const Vector3&);

		Transform();
		~Transform();
	};
}


