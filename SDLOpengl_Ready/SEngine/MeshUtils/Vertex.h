#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include "..\..\Maths\Vector.h"

namespace AREngine 
{
	struct Vertex
	{
		/*glm::vec3 position;
		glm::vec4 color;
		glm::vec3 normal;
		glm::vec2 uv;*/

		Vector3 position;
		Vector4 color;
		Vector3 normal;
		Vector2 uv;
	};
}


