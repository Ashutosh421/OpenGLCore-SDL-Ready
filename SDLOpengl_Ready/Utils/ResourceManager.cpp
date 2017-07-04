#include "ResourceManager.h"

std::string ResourceManager::LoadTextFromFile(const char* filePath) {

	std::fstream file;
	file.open(filePath ,std::ios::in | std::ios::out);


	std::stringstream fileContent;
	//std::cout << "Trying to Read the File " << filePath << std::endl;

	if (!file.is_open())
	{
		std::cout << "Couldn't open the File " << std::endl;
		return "Error!";
	}
	else 
	{
//		std::cout << "File successfully opened " << std::endl;
		std::string lineData;
		while (getline(file, lineData))
		{
			fileContent << lineData << "\n";
		}
		file.close();

		//std::cout << "File Content is " << std::endl << fileContent.str() << std::endl;
		return fileContent.str();
	}
}

