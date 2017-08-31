#include "TextureManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "..\ImageLoader\stb_image.h"

namespace AREngine {

	std::string  TextureManager::texturebasePath = "Assets/Textures/";
	std::map<std::string, Image*> TextureManager::textures;

	const Image* TextureManager::LoadTexture(std::string imagePath) {
	//	std::string imagePath = texturebasePath + textureName;
		stbi_set_flip_vertically_on_load(true);
		auto textureIterator = textures.begin();

		for (textureIterator = textures.begin(); textureIterator != textures.end(); ++textureIterator)
		{
			if (textureIterator->first == imagePath)
			{
			//	std::cout << "Already Got Data "<< std::endl;
				return textureIterator->second;
			}
		}

		Image* newImage = new Image();
		newImage->imageData = stbi_load(imagePath.c_str(), &newImage->width, &newImage->height, &newImage->channels, 0);
		if (newImage->imageData == NULL)
		{
			std::cout << "Couldn't load Image " << stbi__err << std::endl;
			std::cout << "Trying to Load " << imagePath << std::endl;
		}
		textures.insert(std::pair<std::string, Image*>(imagePath , newImage));
		for (textureIterator = textures.begin(); textureIterator != textures.end(); ++textureIterator)
		{
			if (textureIterator->first == imagePath)
			{	
//				std::cout << "Added New Image " << std::endl;
				return textureIterator->second;
			}
		}
	}

	void TextureManager::Clean()
	{
		auto textureIterator = textures.begin();
		for (textureIterator = textures.begin(); textureIterator != textures.end(); ++textureIterator)
		{
		//	delete textureIterator->second;
			stbi_image_free(textureIterator->second);
		}
	}
}


