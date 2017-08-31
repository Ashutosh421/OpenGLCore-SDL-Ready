#pragma once
#include <string>
#include <GL/glew.h>
#include "../../Utils/ResourceManager.h"
#include "../../Maths/Color.h"
#include "ShaderManager.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

namespace AREngine 
{
	class Shader 
	{
	private:
		const char* vertexSource;
		const char* fragmentSource;

		GLuint vertexShader;
		GLuint fragmentShader;

		GLint modelMatrix_Location;
		GLint viewMatrix_Location;
		GLint projectionMatrix_Location;

		bool CheckShaderError(GLuint, GLenum, GLboolean, std::string);
		GLint GetUniform_Location(std::string);

	public:
		GLuint shaderProgram;
		Shader(std::string, std::string);

		void UpdateShader(std::string, std::string);
		void SetModelMatrix(glm::mat4);
		void SetViewMatrix(glm::mat4);
		void SetProjectionMatrix(glm::mat4);

		void SetUniform_Color(const Color* color);
		void SetUniform_Matrix4f(const std::string& , const glm::mat4&);
		void SetUniform_Vec3(const std::string&, const glm::vec3&);
		void SetUniform_Vec4(const std::string&, const glm::vec4&);
		void SetUniform_Float(const std::string& , const float&);
		void SetUniform_Int(const std::string& , const int&);

		void BindShader() ;
		void UnbindShader() const;

		~Shader();
	};
}


