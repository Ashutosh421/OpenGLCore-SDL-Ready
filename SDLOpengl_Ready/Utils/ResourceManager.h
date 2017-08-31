#ifndef RESOURCEM
#define RESOURCEM

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SDL.h>
#include "../SEngine/ImageLoader/stb_image.h"

class ResourceManager final
{

public:
	static std::string LoadTextFromFile(const char* filePath);
	static char* LoadPixelsFromImage(const char* imagePath);
};

#endif // !RESOURCEM
