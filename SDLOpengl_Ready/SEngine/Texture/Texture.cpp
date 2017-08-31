#include "Texture.h"

namespace AREngine {
	Texture::Texture()
	{

	}

	Texture::Texture(std::string textureName)
	{
		this->UpdateImage(textureName);
	}

	void Texture::UpdateImage(std::string imageName) {
		this->image = TextureManager::LoadTexture(imageName);

		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S , GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T , GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER , GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER , GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->image->width, this->image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->image->imageData);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	void Texture::Bind(){
		glBindTexture(GL_TEXTURE_2D, textureID);
		glActiveTexture(GL_TEXTURE0);
	}

	void Texture::Unbind() {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1 , &textureID);
	}
}

