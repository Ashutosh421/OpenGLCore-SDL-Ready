#pragma once
#include <iostream>
#include <GL\glew.h>
#include "Vertex.h"

namespace AREngine
{
	class Mesh final
	{
	private:
		Vertex* m_vertices;
		GLuint m_vertexBufferObject =  0; //Header Initialization
		GLuint m_vertexArrayObject  =  0;  //Header Initialization
		GLuint m_drawSize;

	public:
		Mesh();
		Mesh(Vertex* , const int&);
		void UpdateVertices(Vertex*, const int&);

		~Mesh();

		void Draw();
	};
}



