#ifndef RESOURCEM
#define RESOURCEM

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class ResourceManager
{

public:
	static std::string LoadTextFromFile(const char* filePath);
	
};

#endif // !RESOURCEM
