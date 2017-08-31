#pragma once

#include "../Transform/Transform.h"
#include "../MeshUtils/Mesh.h"
#include "../Shader/Shader.h"
#include "../Shader/ShaderManager.h"
#include "../Camera/Camera.h"
#include "../Texture/Texture.h"

namespace AREngine {

	class Entity
	{
	protected:
		Vertex* vertices = nullptr;

	public:
		Transform* transform;
		Mesh* mesh;
		Shader* shader;
		Camera* viewCamera;
	    std::vector<Texture*> textures;

		virtual void update() = 0;
		virtual void setShader   (std::string , std::string) = 0;
		virtual void setTexture (std::string) = 0;
		void setTextureTiling(unsigned short, unsigned short);

		void SetViewCamera(Camera* viewCamera);
		Entity();
		~Entity();
	};
}


