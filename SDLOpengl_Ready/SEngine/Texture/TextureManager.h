#pragma once
#include <map>
#include <string>
#include <iostream>

namespace AREngine 
{
	class Image {

	public:
		int width;
		int height;
		int channels;
		const unsigned char* imageData;
	};

	class TextureManager
	{

	private:
		static std::string texturebasePath;
		static std::map<std::string, Image*> textures;

	public:
		static const Image* LoadTexture(std::string);
		static void Clean();
	};
}



