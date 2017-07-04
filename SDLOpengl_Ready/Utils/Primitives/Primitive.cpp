#include "Primitive.h"

namespace AREngine
{
	Primitive::Primitive()
	{
		vertices = nullptr;
		mesh = nullptr;
	}

	Primitive::~Primitive()
	{
		delete vertices;
		delete mesh;
	}

	Triangle::Triangle()
	{	
		vertices = new Vertex[3];
		vertices[0].position = glm::vec3(-0.5f , -0.5f , 0);
		vertices[1].position = glm::vec3(0.5f  , -0.5f , 0);
		vertices[2].position = glm::vec3(0.0f  ,  0.5f , 0);

		vertices[0].color = glm::vec4(0.0f , 1.0f , 0.0f , 1.0f );
		vertices[1].color = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		vertices[2].color = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);

		mesh = new Mesh(vertices, 3);
	}

	Triangle::~Triangle()
	{	
		delete[] vertices;
		delete mesh;
	}

	void Triangle::Draw()
	{
		mesh->Draw();
	}

	void Triangle::SetShader(std::string vertexShader, std::string fragmentShader) 
	{
		mesh->SetShader(vertexShader , fragmentShader);
	}

	Quad::Quad()
	{	
		vertices = new Vertex[6];

		vertices[0].position = glm::vec3(-0.5f, -0.5f, 0);
		vertices[1].position = glm::vec3( 0.5f, -0.5f, 0);
		vertices[2].position = glm::vec3( 0.5f,  0.5f, 0);
		vertices[3].position = glm::vec3( 0.5f,  0.5f, 0);
		vertices[4].position = glm::vec3(-0.5f,  0.5f, 0);
		vertices[5].position = glm::vec3(-0.5f, -0.5f, 0);

		vertices[0].color = glm::vec4( 0.0f , 1.0f , 0.0f , 1.0f);
		vertices[1].color = glm::vec4( 0.0f , 1.0f , 0.0f , 1.0f);
		vertices[2].color = glm::vec4( 0.0f , 1.0f , 0.0f , 1.0f);
		vertices[3].color = glm::vec4( 0.0f , 1.0f , 0.0f , 1.0f);
		vertices[4].color = glm::vec4( 0.0f , 1.0f , 0.0f , 1.0f);
		vertices[5].color = glm::vec4( 0.0f , 1.0f , 0.0f , 1.0f);

		mesh = new Mesh(vertices, 6);
	}

	void Quad::Draw() {
		mesh->Draw();
	}

	void Quad::SetShader(std::string vertexShader, std::string fragmentShader) 
	{
		mesh->SetShader(vertexShader, fragmentShader);
	}

	Quad::~Quad()
	{
	}
}
