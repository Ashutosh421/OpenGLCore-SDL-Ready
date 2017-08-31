#include "Mesh.h"

namespace AREngine
{
	Mesh::Mesh() {
		this->m_vertices = 0;
		this->m_drawSize = 0;
	}

	Mesh::Mesh(Vertex* vertices, const int& size)
	{
		UpdateVertices(vertices , size);
	}

	void Mesh::UpdateVertices(Vertex* vertices, const int& size) {
		this->m_vertices = vertices;
		this->m_drawSize = size;

		glGenVertexArrays(1, &m_vertexArrayObject);
		glBindVertexArray(m_vertexArrayObject);

		glGenBuffers(1, &m_vertexBufferObject);
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * size, vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(AREngine::Vertex), 0);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(AREngine::Vertex), (void*)offsetof(Vertex, color));
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(AREngine::Vertex), (void*)offsetof(Vertex, normal));
		glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(AREngine::Vertex), (void*)offsetof(Vertex, uv));

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Mesh::Draw() 
	{
		glBindVertexArray(m_vertexArrayObject);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);

		glDrawArrays(GL_TRIANGLES , 0 , this->m_drawSize);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glDisableVertexAttribArray(3);
		glBindVertexArray(0);
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(1, &m_vertexBufferObject);
		glDeleteVertexArrays(1, &m_vertexArrayObject);
		delete[] m_vertices;
	}
}  


