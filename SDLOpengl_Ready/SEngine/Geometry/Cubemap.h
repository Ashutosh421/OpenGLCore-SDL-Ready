#pragma once
#include <GL/glew.h>
#include "../Entity/Entity.h"
#include "../Texture/TextureManager.h"

namespace AREngine {

	class Cubemap : public Entity
	{
	private:
		GLuint cubemapID;
		std::vector<const Image*> faces;

		void setVertices();

	public:
		void update() override;
		void setShader(std::string, std::string) override;
		void setTexture(std::string) override;
	
		Cubemap(std::string);
		~Cubemap();
	};
}


