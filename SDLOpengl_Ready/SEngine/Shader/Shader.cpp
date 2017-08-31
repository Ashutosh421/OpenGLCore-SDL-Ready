#include "Shader.h"

namespace AREngine 
{
	Shader::Shader(std::string vertexSource, std::string fragmentSource)
	{
		this->shaderProgram = -1;
		UpdateShader(vertexSource , fragmentSource);
	}

	void Shader::UpdateShader(std::string vertexSource, std::string fragmentSource) {
		if (this->shaderProgram != -1)
		{
			glUseProgram(0);
			glDeleteProgram(this->shaderProgram);
		}
		vertexShader = glCreateShader(GL_VERTEX_SHADER); //Creating the VERTEX SHADER
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); //Creating the FRAGMENT SHADER

		std::string vertSource = ResourceManager::LoadTextFromFile(vertexSource.c_str());
		std::string fragSource = ResourceManager::LoadTextFromFile(fragmentSource.c_str());

		this->vertexSource = vertSource.c_str();
		this->fragmentSource = fragSource.c_str();

		//Filling in the Vertex Shader Data
		glShaderSource(this->vertexShader, 1, &(this->vertexSource), NULL);
		//Filling in the Fragment Shader Data
		glShaderSource(this->fragmentShader, 1, &(this->fragmentSource), NULL);

		glCompileShader(this->vertexShader); //Compiling the VERTEX SHADER
		if (CheckShaderError(this->vertexShader, GL_COMPILE_STATUS, GL_FALSE, "Vertex Shader Compile Error"))
		{
		//	std::cout << "Vertex Shader Successfully Compiled " << std::endl;
		}
		else {
			return;
		}

		glCompileShader(this->fragmentShader); //Compiling the FRAGMENT SHADER
		if (CheckShaderError(this->fragmentShader, GL_COMPILE_STATUS, GL_FALSE, "Fragment Shader Compile Error"))
		{
			//std::cout << "Fragment Shader Successfully compiled " << std::endl;
		}
		else {
			return;
		}

		this->shaderProgram = glCreateProgram();
		glAttachShader(this->shaderProgram, this->vertexShader);
		glAttachShader(this->shaderProgram, this->fragmentShader);
		glUseProgram(this->shaderProgram);

		glLinkProgram(this->shaderProgram);
		//Note the different functions here: glGetProgram* instead of glGetShader*.
		if (CheckShaderError(this->shaderProgram, GL_LINK_STATUS, GL_TRUE, "Shader Program Link Error "))
		{
			//std::cout << "Link Successfull" << std::endl;;
		}
		glValidateProgram(this->shaderProgram);
		if (CheckShaderError(this->shaderProgram, GL_VALIDATE_STATUS, GL_TRUE, "Shader Program Validation Error "))
		{
			//std::cout << "Link Successfull" << std::endl;;
		}

		glDetachShader(this->shaderProgram, this->vertexShader);
		glDetachShader(this->shaderProgram, this->fragmentShader);
		glDeleteShader(this->vertexShader);
		glDeleteShader(this->fragmentShader);
		glUseProgram(this->shaderProgram);
		this->modelMatrix_Location = GetUniform_Location("modelMatrix");
		this->viewMatrix_Location = GetUniform_Location("viewMatrix");
		this->projectionMatrix_Location = GetUniform_Location("projectionMatrix");
	}

	void Shader::SetModelMatrix(glm::mat4 modelMatrix) {
		glUniformMatrix4fv(this->modelMatrix_Location, 1, GL_FALSE, glm::value_ptr(modelMatrix));
	}

	void Shader::SetViewMatrix(glm::mat4 viewMatrix) {
		glUniformMatrix4fv(this->viewMatrix_Location, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	}

	void Shader::SetProjectionMatrix(glm::mat4 projectionMatrix) {
		glUniformMatrix4fv(this->projectionMatrix_Location , 1 , GL_FALSE , glm::value_ptr(projectionMatrix));
	}

	void Shader::SetUniform_Vec3(const std::string& fieldName, const glm::vec3& value) {
		GLint location = glGetUniformLocation(this->shaderProgram, fieldName.c_str());
		glUniform3fv(location, 1, glm::value_ptr(value));
	}

	void Shader::SetUniform_Vec4(const std::string& fieldName , const glm::vec4& value) {
		GLint location = glGetUniformLocation(this->shaderProgram, fieldName.c_str());
		glUniform4fv(location , 1 , glm::value_ptr(value));
	}

	void Shader::SetUniform_Matrix4f(const std::string& fieldName ,const glm::mat4& value) {
		GLint location = glGetUniformLocation(this->shaderProgram , fieldName.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}

	void Shader::SetUniform_Float(const std::string& uniformName, const float& value) {
		GLint location = glGetUniformLocation(this->shaderProgram, uniformName.c_str());
		glUniform1f(location, value);
	}

	void Shader::SetUniform_Int(const std::string& uniformName , const int& value) {
		GLint location = glGetUniformLocation(this->shaderProgram , uniformName.c_str());
		glUniform1i(location, value);
	}

	void Shader::SetUniform_Color(const Color* color) {
		this->SetUniform_Float("baseColor.r" , color->r);
		this->SetUniform_Float("baseColor.b" , color->b);
		this->SetUniform_Float("baseColor.g" , color->g);
		this->SetUniform_Float("baseColor.a" , color->a);
	}

	bool Shader::CheckShaderError(GLuint program_Or_Shader, GLenum checkType, GLboolean isProgram, std::string errortype)
	{
		char infoLOG[512];
		GLint status = 0;
		if (!isProgram)
		{
			glGetShaderiv(program_Or_Shader, checkType, &status);
			if (status == GL_FALSE)
			{
				glGetShaderInfoLog(program_Or_Shader, 512, NULL, infoLOG);
				std::cout << errortype << infoLOG << std::endl;
				glDeleteShader(this->vertexShader);
				glDeleteShader(this->fragmentShader);
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
				glDeleteProgram(this->shaderProgram);
				return false;
			}
		}
		return true;
	}

	void Shader::BindShader() 
	{
		glUseProgram(this->shaderProgram);
	}

	void Shader::UnbindShader() const
	{
		glUseProgram(0);
	}
	
	GLint Shader::GetUniform_Location(std::string location) 
	{
	   return glGetUniformLocation(this->shaderProgram, location.c_str());
	}

	Shader::~Shader()
	{
		glDeleteProgram(this->shaderProgram);
	}
}

