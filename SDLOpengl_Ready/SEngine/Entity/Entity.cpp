#include "Entity.h"

namespace AREngine {
	Entity::Entity()
	{
		this->vertices = nullptr;
		this->transform = new Transform();
		this->mesh = new Mesh();
		this->shader = new Shader(ShaderManager::DEFAULT_VERTEXSHADER, ShaderManager::DEFAULT_FRAGMENTSHADER);
		this->material = new Material();
	}

	void Entity::SetViewCamera(Camera* viewCamera) {
		this->viewCamera = viewCamera;
	}

	void Entity::setTextureTiling(unsigned short tileX , unsigned short tileY) {
		this->shader->SetUniform_Float("textureTile.x",tileX);
		this->shader->SetUniform_Float("textureTile.y", tileY);
	}

	Entity::~Entity()
	{
		delete this->transform;
		delete this->mesh;
		delete this->shader;
		delete this->vertices;
		delete this->material;
		for (auto i = textures.begin(); i <= textures.end(); i++)
		{
			delete *i;
		}
	}
}


