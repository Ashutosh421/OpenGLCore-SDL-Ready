#pragma once
#include <string>
#include <GL\glew.h>
#include "../ResourceManager.h"

namespace AREngine 
{
	class Shader
	{
	private:
		const char* vertexSource;
		const char* fragmentSource;

		GLuint vertexShader;
		GLuint fragmentShader;

		bool CheckShaderError(GLuint, GLenum, GLboolean, std::string);

	public:
		GLuint shaderProgram;

		Shader(std::string, std::string);

		void BindShader();
		void UnbindShader();

		~Shader();
	};
}


