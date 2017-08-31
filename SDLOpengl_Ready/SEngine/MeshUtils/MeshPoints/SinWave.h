#include <iostream>
#include <GL\glew.h>
#include "..\Vertex.h"
#include "..\..\Shader\Shader.h"
#include <memory>
#include <thread>

namespace AREngine {
	class SinWave
	{

	private:
		AREngine::Vertex* vertices;
		AREngine::Shader* shader;

		GLuint vertexArrayObject;
		GLuint vertexBufferObject;

		GLuint numberOfParticles;

	public:
		GLfloat frequency;
		unsigned int particles;

		void Update();
		void CheckVertices();
		void SetShader(std::string, std::string);

		SinWave();
		~SinWave();
	};
}

