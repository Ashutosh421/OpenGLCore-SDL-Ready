#include "Shader.h"

namespace AREngine 
{
	Shader::Shader(std::string vertexSource, std::string fragmentSource)
	{
		vertexShader = glCreateShader(GL_VERTEX_SHADER); //Creating the VERTEX SHADER
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); //Creating the FRAGMENT SHADER

		std::string vertSource = ResourceManager::LoadTextFromFile(vertexSource.c_str()).c_str();
		std::string fragSource = ResourceManager::LoadTextFromFile(fragmentSource.c_str()).c_str();

		this->vertexSource = vertSource.c_str();
		this->fragmentSource = fragSource.c_str();
	//	std::cout << "Vertex Source " << std::endl << this->vertexSource << std::endl;
//		std::cout << "Fragment Source " << std::endl << this->fragmentSource << std::endl;

		//Filling in the Vertex Shader Data
		glShaderSource(this->vertexShader, 1, &(this->vertexSource), NULL);
		//Filling in the Fragment Shader Data
		glShaderSource(this->fragmentShader, 1, &(this->fragmentSource), NULL);

		glCompileShader(this->vertexShader); //Compiling the VERTEX SHADER
		if (CheckShaderError(this->vertexShader, GL_COMPILE_STATUS, GL_FALSE, "Vertex Shader Compile Error"))
		{
			std::cout << "Vertex Shader Successfully Compiled " << std::endl;
		}

		glCompileShader(this->fragmentShader); //Compiling the FRAGMENT SHADER
		if (CheckShaderError(this->vertexShader, GL_COMPILE_STATUS, GL_FALSE, "Fragment Shader Compile Error"))
		{
			std::cout << "Fragment Shader Successfully compiled " << std::endl;
		}

		this->shaderProgram = glCreateProgram();
		glAttachShader(this->shaderProgram, this->vertexShader);
		glAttachShader(this->shaderProgram, this->fragmentShader);

		glLinkProgram(this->shaderProgram);
		if (CheckShaderError(this->shaderProgram, GL_LINK_STATUS, GL_FALSE, "Shader Program Link Error"))
		{
			std::cout << "Program Linked Successfully " << std::endl;
		}
		glDeleteShader(this->vertexShader);
		glDeleteShader(this->fragmentShader);
	}

	bool Shader::CheckShaderError(GLuint program_Or_Shader, GLenum checkType, GLboolean isProgram, std::string errortype)
	{
		char infoLOG[512];
		GLint status;
		if (!isProgram)
		{
			glGetShaderiv(program_Or_Shader, checkType, &status);
			if (status == GL_FALSE)
			{
				glGetShaderInfoLog(program_Or_Shader, 512, NULL, infoLOG);
				std::cout << errortype << infoLOG << std::endl;
				return false;
			}
		}
		else
		{
			glGetProgramiv(program_Or_Shader, checkType, &status);
			if (status == GL_FALSE)
			{
				glGetShaderInfoLog(program_Or_Shader, 512, NULL, infoLOG);
				std::cout << errortype << infoLOG << std::endl;
				return false;
			}
		}
		return true;
	}

	void Shader::BindShader() 
	{
		glUseProgram(this->shaderProgram);
	}

	void Shader::UnbindShader() 
	{
		glUseProgram(0);
	}

	Shader::~Shader()
	{
		glDeleteProgram(this->shaderProgram);
	}

}

