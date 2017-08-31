#include "Light.h"

namespace AREngine 
{
	Light::Light()
	{
		setLightVertices();
		mesh = new Mesh();
		mesh->UpdateVertices(vertices, 36);
		transform = new Transform();
		shader = new Shader(ShaderManager::DEFAULT_VERTEXSHADER_LIGHT, ShaderManager::DEFAULT_FRAGMENTSHADER_LIGHT);
		lightColor = new Color();
		this->setColor(*lightColor);
		this->intensity = 1.0f;
	}

	void Light::setColor(const Color& color) {
		this->lightColor->r = color.r;
		this->lightColor->g = color.g;
		this->lightColor->b = color.b;
		this->lightColor->a = color.a;
		this->shader->SetUniform_Color(this->lightColor);
	}

	void Light::setViewCamera(Camera* viewCamera) {
	 	this->viewCamera = viewCamera;
	}

	void Light::setLightVertices() {
		vertices = new Vertex[36];

		this->vertices[0].position = Vector3(-0.5f, 0.5f, -0.5f); //Back
		this->vertices[1].position = Vector3(-0.5f, -0.5f, -0.5f);
		this->vertices[2].position = Vector3(0.5f, -0.5f, -0.5f);
		this->vertices[3].position = Vector3(0.5f, -0.5f, -0.5f);
		this->vertices[4].position = Vector3(0.5f, 0.5f, -0.5f);
		this->vertices[5].position = Vector3(-0.5f, 0.5f, -0.5f);

		this->vertices[6].position = Vector3(-0.5f, -0.5f, 0.5f);   //Left
		this->vertices[7].position = Vector3(-0.5f, -0.5f, -0.5f);
		this->vertices[8].position = Vector3(-0.5f, 0.5f, -0.5f);
		this->vertices[9].position = Vector3(-0.5f, 0.5f, -0.5f);
		this->vertices[10].position = Vector3(-0.5f, 0.5f, 0.5f);
		this->vertices[11].position = Vector3(-0.5f, -0.5f, 0.5f);

		this->vertices[12].position = Vector3(0.5f, -0.5f, -0.5f);   //Right
		this->vertices[13].position = Vector3(0.5f, -0.5f, 0.5f);
		this->vertices[14].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[15].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[16].position = Vector3(0.5f, 0.5f, -0.5f);
		this->vertices[17].position = Vector3(0.5f, -0.5f, -0.5f);

		this->vertices[18].position = Vector3(-0.5f, -0.5f, 0.5f);  //Front
		this->vertices[19].position = Vector3(-0.5f, 0.5f, 0.5f);
		this->vertices[20].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[21].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[22].position = Vector3(0.5f, -0.5f, 0.5f);
		this->vertices[23].position = Vector3(-0.5f, -0.5f, 0.5f);

		this->vertices[24].position = Vector3(-0.5f, 0.5f, -0.5f); //Top
		this->vertices[25].position = Vector3(0.5f, 0.5f, -0.5f);
		this->vertices[26].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[27].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[28].position = Vector3(-0.5f, 0.5f, 0.5f);
		this->vertices[29].position = Vector3(-0.5f, 0.5f, -0.5f);

		this->vertices[30].position = Vector3(-0.5f, -0.5f, -0.5f); //Down
		this->vertices[31].position = Vector3(-0.5f, -0.5f, 0.5f);
		this->vertices[32].position = Vector3(0.5f, -0.5f, -0.5f);
		this->vertices[33].position = Vector3(0.5f, -0.5f, -0.5f);
		this->vertices[34].position = Vector3(-0.5f, -0.5f, 0.5f);
		this->vertices[35].position = Vector3(0.5f, -0.5f, 0.5f);
	}

	Light::~Light()
	{
		delete mesh;
		delete transform;
		delete shader;
	}
}

