#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>

namespace AREngine 
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec4 color;
		glm::vec3 normal;
		glm::vec2 uv;
	};
}


