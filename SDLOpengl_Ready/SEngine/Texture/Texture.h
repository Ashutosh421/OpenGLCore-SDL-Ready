#pragma once
#include <string>
#include <GL\glew.h>
#include "TextureManager.h"

namespace AREngine 
{
	class Texture
	{
	private:
		const Image* image;
		GLuint textureID;

	public:
		Texture();
		Texture(std::string imageName);
		void UpdateImage(std::string);
		void Bind();
		void Unbind();
		~Texture();
	};
}



