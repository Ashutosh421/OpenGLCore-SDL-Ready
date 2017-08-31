#pragma once
#include "../../Maths/Vector.h"
#include "../../Utils/Display.h"
#include "../../Utils/Input/Input.h"
#include "../Time/Time.h"
#include "../Transform/Transform.h"
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace AREngine {
	class Camera
	{
	private:
		glm::mat4 viewMatrix;
		glm::mat4 projectionMatrix;
		Vector3 lookATTarget;

	public:
		enum  Projection
		{
			ORTHOGRAPHIC,
			PERSPECTIVE
		}projection;

		Vector3 forward;
		Vector3 up;
		Vector3 right;

		Transform* transform;

		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();
	
		void SetProjection(Projection);
		void update();
		void LookAT(const Vector3&);

		Camera();
		~Camera();
	};
}

