#include "Entity.h"

namespace AREngine {
	Entity::Entity()
	{
		this->vertices = nullptr;
		this->transform = new Transform();
		this->mesh = new Mesh();
		this->shader = new Shader(ShaderManager::DEFAULT_VERTEXSHADER, ShaderManager::DEFAULT_FRAGMENTSHADER);
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
		for (auto i = textures.begin(); i <= textures.end(); i++)
		{
			delete *i;
		}
	}
}


