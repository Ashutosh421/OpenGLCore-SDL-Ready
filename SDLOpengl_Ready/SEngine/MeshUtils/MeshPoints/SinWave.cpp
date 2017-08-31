#include "SinWave.h"

namespace AREngine {

	SinWave::SinWave()
	{
		glPointSize(5.0f);
		this->shader = nullptr;
		vertexBufferObject = 0;
		this->particles = 100;
		this->vertices = new AREngine::Vertex[this->particles];
	//	AREngine::Vertex vert[3];
		/*this->vertices[0].position = glm::vec3(-0.5f, -0.5f, 0);
		this->vertices[1].position = glm::vec3(0.5f, -0.5f, 0);
		this->vertices[2].position = glm::vec3(0.0f, 0.5f, 0);

		this->vertices[0].color = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		this->vertices[1].color = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		this->vertices[2].color = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);*/
		
		double xPos = -(this->particles/2 * 0.02f);
		double yPos = 0;
		for (size_t i = 0; i < this->particles  ; i ++)
		{
			this->vertices[i].position = Vector3( xPos , yPos , 0.0f);
			this->vertices[i].color = Vector4(0.0f , 1.0f , 0.0f , 0.0f);

			xPos += 0.02f;
			yPos = sin((xPos * 500)* (3.14 / 180)) * 0.25f;
		}
		
		this->numberOfParticles = this->particles;
		std::cout << "Number of Particles " << this->numberOfParticles << std::endl;
		std::cout << "Size of Vertices " << sizeof(this->vertices[0]) * this->numberOfParticles << std::endl;
		//std::cout << "Size of Vertex " << sizeof(this->vertices[0]) << std::endl;

		glGenVertexArrays(1, &vertexArrayObject);
		glBindVertexArray(vertexArrayObject);

		glGenBuffers(1, &vertexBufferObject);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

		glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices[0]) * this->numberOfParticles, this->vertices, GL_STATIC_DRAW);
	
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE , sizeof(AREngine::Vertex), (void*)0);
		glVertexAttribPointer(1 ,4, GL_FLOAT, GL_TRUE  , sizeof(AREngine::Vertex), (void*)(3 * sizeof(GL_FLOAT)));
		//glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE  , sizeof(AREngine::Vertex), (void*)(7 * sizeof(GL_FLOAT)));
		//glVertexAttribPointer(3, 2, GL_FLOAT, GL_TRUE  , sizeof(AREngine::Vertex), (void*)(10 * sizeof(GL_FLOAT)));

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
	
		glBindBuffer(GL_VERTEX_ARRAY , 0);
		
		//CheckVertices();
	}



	void SinWave::CheckVertices() 
	{
		for (size_t i = 0; i < this->numberOfParticles; i++)
		{
			std::cout << "Vertices " << vertices[i].position.x  << " , " << vertices[i].position.y << std::endl;
		}
	}

	void SinWave::SetShader(std::string vertexShaderPath , std::string fragmentShaderPath) 
	{
		this->shader = new AREngine::Shader(vertexShaderPath , fragmentShaderPath);
	}

	void SinWave::Update()
	{	
		if (this->shader != nullptr)
		{
			this->shader->BindShader();
		}

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glDrawArrays(GL_POINTS, 0, this->numberOfParticles);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		if (this->shader != nullptr)
		{
			this->shader->UnbindShader();
		}
	}

	SinWave::~SinWave()
	{
		glPointSize(1.0f);
		delete[] this->vertices;
		glBindVertexArray(0);
		glDeleteVertexArrays(1, &vertexArrayObject);
		glDeleteBuffers(GL_VERTEX_ARRAY, &vertexBufferObject);
	}
}

