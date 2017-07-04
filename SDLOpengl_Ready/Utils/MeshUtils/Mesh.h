#pragma once
#include <iostream>
#include <GL\glew.h>
#include "Vertex.h"
#include "..\Shader\Shader.h"

namespace AREngine
{
	class Mesh
	{
	private:
		Vertex* m_vertices;
		GLuint m_vertexBufferObject =  0; //Header Initialization
		GLuint m_vertexArrayObject  =  0;  //Header Initialization
		GLuint m_drawSize;
	public:
		Shader* shader;

		Mesh(Vertex* , const int&);
		~Mesh();

		void Draw();
		void SetShader(std::string , std::string);
	};
}



