#include "Cubemap.h"

namespace AREngine
{
	Cubemap::Cubemap(std::string folderPath)
	{
		this->shader->UpdateShader("Assets/Shaders/Skybox/Vertex_Shader_Cubemap.ves", "Assets/Shaders/Skybox/Fragment_Shader_Cubemap.fes");
		this->setVertices();
		//Setup CubeMap Textures
		glEnable(GL_TEXTURE_CUBE_MAP);
		glGenTextures(1, &cubemapID);
		glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapID);
	
		std::string texturePath;
		const Image* newImage;

		for (int i = 0 ; i < 6 ; i++)
		{	
			texturePath = folderPath + "/"+ std::to_string(i) +".tga";
			newImage = TextureManager::LoadTexture(texturePath);
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0 , GL_RGB , newImage->width , newImage->height , 0 , GL_RGB , GL_UNSIGNED_BYTE, newImage->imageData);
		}

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		//glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	}

	void Cubemap::setVertices() {
		this->vertices = new Vertex[36];

		this->vertices[0].position = Vector3(-1.0f, 1.0f, -1.0f);
		this->vertices[1].position = Vector3(-1.0f, -1.0f, -1.0f);
		this->vertices[2].position = Vector3(1.0f, -1.0f, -1.0f);
		this->vertices[3].position = Vector3(1.0f, -1.0f, -1.0f);
		this->vertices[4].position = Vector3(1.0f, 1.0f, -1.0f);
		this->vertices[5].position = Vector3(-1.0f, 1.0f, -1.0f);

		this->vertices[6].position = Vector3(-1.0f, -1.0f, 1.0f);
		this->vertices[7].position = Vector3(-1.0f, -1.0f, -1.0f);
		this->vertices[8].position = Vector3(-1.0f, 1.0f, -1.0f);
		this->vertices[9].position = Vector3(-1.0f, 1.0f, -1.0f);
		this->vertices[10].position = Vector3(-1.0f, 1.0f, 1.0f);
		this->vertices[11].position = Vector3(-1.0f, -1.0f, 1.0f);

		this->vertices[12].position = Vector3(1.0f, -1.0f, -1.0f);
		this->vertices[13].position = Vector3(1.0f, -1.0f,  1.0f);
		this->vertices[14].position = Vector3(1.0f,  1.0f,  1.0f);
		this->vertices[15].position = Vector3(1.0f,  1.0f,  1.0f);
		this->vertices[16].position = Vector3(1.0f,  1.0f, -1.0f);
		this->vertices[17].position = Vector3(1.0f, -1.0f, -1.0f);

		this->vertices[18].position = Vector3(-1.0f, -1.0f, 1.0f);
		this->vertices[19].position = Vector3(-1.0f, 1.0f, 1.0f);
		this->vertices[20].position = Vector3(1.0f, 1.0f, 1.0f);
		this->vertices[21].position = Vector3(1.0f, 1.0f, 1.0f);
		this->vertices[22].position = Vector3(1.0f, -1.0f, 1.0f);
		this->vertices[23].position = Vector3(-1.0f, -1.0f, 1.0f);

		this->vertices[24].position = Vector3(-1.0f, 1.0f, -1.0f);
		this->vertices[25].position = Vector3(1.0f, 1.0f, -1.0f);
		this->vertices[26].position = Vector3(1.0f, 1.0f, 1.0f);
		this->vertices[27].position = Vector3(1.0f, 1.0f, 1.0f);
		this->vertices[28].position = Vector3(-1.0f, 1.0f, 1.0f);
		this->vertices[29].position = Vector3(-1.0f, 1.0f, -1.0f);

		this->vertices[30].position = Vector3(-1.0f, -1.0f, -1.0f);
		this->vertices[31].position = Vector3(-1.0f, -1.0f, 1.0f);
		this->vertices[32].position = Vector3(1.0f, -1.0f, -1.0f);
		this->vertices[33].position = Vector3(1.0f, -1.0f, -1.0f);
		this->vertices[34].position = Vector3(-1.0f, -1.0f, 1.0f);
		this->vertices[35].position = Vector3(1.0f, -1.0f, 1.0f);

		this->mesh->UpdateVertices(this->vertices , 36);
	}

	void Cubemap::update() {
		glDepthMask(GL_FALSE);
		glDepthFunc(GL_LEQUAL);
		this->shader->BindShader();

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapID);

		if (this->viewCamera != nullptr)
		{
			//To Create it as a SkyBox
			this->shader->SetViewMatrix(glm::mat4(glm::mat3(this->viewCamera->getViewMatrix()))); 
			
			//To create it as a Simple Cube
		//	this->shader->SetViewMatrix(glm::mat4(this->viewCamera->getViewMatrix()));  
			this->shader->SetProjectionMatrix(this->viewCamera->getProjectionMatrix());
		}
		this->mesh->Draw();

		glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
		this->shader->UnbindShader();
		glDepthFunc(GL_LESS);
		glDepthMask(GL_TRUE);
	}

	void Cubemap::setShader(std::string vertexShader , std::string fragmentShader) {
		this->shader->UpdateShader(vertexShader , fragmentShader);
	}

	void Cubemap::setTexture(std::string) {

	}

	Cubemap::~Cubemap()
	{
		glDeleteTextures(1, &cubemapID);
	}
}


