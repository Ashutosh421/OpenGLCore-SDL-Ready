#include "Geometry.h"

namespace AREngine
{
	Geometry* Geometry::Instantiate(GeometryType geometry) {
		if (geometry == GeometryType::TRIANGLE)
		{
			return new Triangle();
		}
		if (geometry == GeometryType::QUAD)
		{
			return new Quad();
		}
		if (geometry == GeometryType::CUBE)
		{
			return new Cube();
		}
		return nullptr;
	}

	void Geometry::setShader(std::string vertexSource, std::string fragmentSource)
	{
		this->shader->UpdateShader(vertexSource, fragmentSource);
		this->setTextureTiling( 1 , 1);
	}

	void Geometry::setTexture(std::string imageName) {
		Texture* newTexture = new Texture();
		newTexture->UpdateImage(imageName);
		this->textures.push_back(newTexture);
	}

	Triangle::Triangle()
	{
		vertices = new Vertex[3];

		vertices[0].position = Vector3(-0.5f, 0.5f, 0);
		vertices[1].position = Vector3(0.5f, 0.5f, 0);
		vertices[2].position = Vector3(0.0f, -0.5f, 0);

		vertices[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertices[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertices[2].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertices[0].uv = Vector2(0.0f, 0.0f);
		vertices[1].uv = Vector2(1.0f, 0.0f);
		vertices[2].uv = Vector2(0.5f, 1.0f);

		this->mesh->UpdateVertices(vertices , 3);
	}

	Quad::Quad()
	{
		vertices = new Vertex[6];

		vertices[0].position = Vector3(-0.5f, -0.5f, 0);
		vertices[1].position = Vector3(0.5f, -0.5f, 0);
		vertices[2].position = Vector3(0.5f, 0.5f, 0);
		vertices[3].position = Vector3(0.5f, 0.5f, 0);
		vertices[4].position = Vector3(-0.5f, 0.5f, 0);
		vertices[5].position = Vector3(-0.5f, -0.5f, 0);

		vertices[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertices[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertices[2].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertices[3].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertices[4].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertices[5].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertices[0].normal = Vector3( 0.0f, 0.0f, 1.0f );
		vertices[1].normal = Vector3( 0.0f, 0.0f, 1.0f );
		vertices[2].normal = Vector3( 0.0f, 0.0f, 1.0f );
		vertices[3].normal = Vector3( 0.0f, 0.0f, 1.0f );
		vertices[4].normal = Vector3( 0.0f, 0.0f, 1.0f );
		vertices[5].normal = Vector3( 0.0f, 0.0f, 1.0f );

		vertices[0].uv = Vector2( 0.0f , 0.0f );
		vertices[1].uv = Vector2( 1.0f , 0.0f );
		vertices[2].uv = Vector2( 1.0f , 1.0f );
		vertices[3].uv = Vector2( 1.0f , 1.0f );
		vertices[4].uv = Vector2( 0.0f , 1.0f );
		vertices[5].uv = Vector2( 0.0f , 0.0f );

		this->mesh->UpdateVertices(vertices, 6);
	}

	Cube::Cube() {
		this->vertices = new Vertex[36];

		this->vertices[0].position = Vector3(-0.5f, 0.5f, -0.5f); //Back
		this->vertices[1].position = Vector3(-0.5f, -0.5f, -0.5f);
		this->vertices[2].position = Vector3(0.5f, -0.5f, -0.5f);
		this->vertices[3].position = Vector3(0.5f, -0.5f, -0.5f);
		this->vertices[4].position = Vector3(0.5f, 0.5f, -0.5f);
		this->vertices[5].position = Vector3(-0.5f, 0.5f, -0.5f);

		this->vertices[6].position = Vector3(-0.5f, -0.5f, 0.5f);   //Left
		this->vertices[7].position = Vector3(-0.5f, -0.5f, -0.5f);
		this->vertices[8].position = Vector3(-0.5f, 0.5f, -0.5f);
		this->vertices[9].position = Vector3(-0.5f, 0.5f, -0.5f);
		this->vertices[10].position = Vector3(-0.5f, 0.5f, 0.5f);
		this->vertices[11].position = Vector3(-0.5f, -0.5f, 0.5f);

		this->vertices[12].position = Vector3(0.5f, -0.5f, -0.5f);   //Right
		this->vertices[13].position = Vector3(0.5f, -0.5f, 0.5f);
		this->vertices[14].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[15].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[16].position = Vector3(0.5f, 0.5f, -0.5f);
		this->vertices[17].position = Vector3(0.5f, -0.5f, -0.5f);

		this->vertices[18].position = Vector3(-0.5f, -0.5f, 0.5f);  //Front
		this->vertices[19].position = Vector3(-0.5f, 0.5f, 0.5f);
		this->vertices[20].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[21].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[22].position = Vector3(0.5f, -0.5f, 0.5f);
		this->vertices[23].position = Vector3(-0.5f, -0.5f, 0.5f);

		this->vertices[24].position = Vector3(-0.5f, 0.5f, -0.5f); //Top
		this->vertices[25].position = Vector3(0.5f, 0.5f, -0.5f);
		this->vertices[26].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[27].position = Vector3(0.5f, 0.5f, 0.5f);
		this->vertices[28].position = Vector3(-0.5f, 0.5f, 0.5f);
		this->vertices[29].position = Vector3(-0.5f, 0.5f, -0.5f);

		this->vertices[30].position = Vector3(-0.5f, -0.5f, -0.5f); //Down
		this->vertices[31].position = Vector3(-0.5f, -0.5f, 0.5f);
		this->vertices[32].position = Vector3(0.5f, -0.5f, -0.5f);
		this->vertices[33].position = Vector3(0.5f, -0.5f, -0.5f);
		this->vertices[34].position = Vector3(-0.5f, -0.5f, 0.5f);
		this->vertices[35].position = Vector3(0.5f, -0.5f, 0.5f);

		this->vertices[0].normal = Vector3( 0 , 0 , -1.0f ); //Back
		this->vertices[1].normal = Vector3( 0 , 0 , -1.0f );
		this->vertices[2].normal = Vector3( 0 , 0 , -1.0f );
		this->vertices[3].normal = Vector3( 0 , 0 , -1.0f );
		this->vertices[4].normal = Vector3( 0 , 0 , -1.0f );
		this->vertices[5].normal = Vector3( 0 , 0 , -1.0f );

		this->vertices[6].normal =  Vector3( -1.0f , 0, 0 );   //Left
		this->vertices[7].normal =  Vector3( -1.0f, 0, 0 );
		this->vertices[8].normal =  Vector3( -1.0f, 0, 0 );
		this->vertices[9].normal =  Vector3( -1.0f, 0, 0 );
		this->vertices[10].normal = Vector3( -1.0f, 0, 0 );
		this->vertices[11].normal = Vector3( -1.0f, 0, 0 );

		this->vertices[12].normal = Vector3( 1.0f, 0, 0 );   //Right
		this->vertices[13].normal = Vector3( 1.0f, 0, 0 );
		this->vertices[14].normal = Vector3( 1.0f, 0, 0 );
		this->vertices[15].normal = Vector3( 1.0f, 0, 0 );
		this->vertices[16].normal = Vector3( 1.0f, 0, 0 );
		this->vertices[17].normal = Vector3( 1.0f, 0, 0 );

		this->vertices[18].normal = Vector3( 0, 0, 1.0f );  //Front
		this->vertices[19].normal = Vector3( 0, 0, 1.0f );
		this->vertices[20].normal = Vector3( 0, 0, 1.0f );
		this->vertices[21].normal = Vector3( 0, 0, 1.0f );
		this->vertices[22].normal = Vector3( 0, 0, 1.0f );
		this->vertices[23].normal = Vector3( 0, 0, 1.0f );

		this->vertices[24].normal = Vector3( 0, 1.0f, 0 ); //Top
		this->vertices[25].normal = Vector3( 0, 1.0f, 0 );
		this->vertices[26].normal = Vector3( 0, 1.0f, 0 );
		this->vertices[27].normal = Vector3( 0, 1.0f, 0 );
		this->vertices[28].normal = Vector3( 0, 1.0f, 0 );
		this->vertices[29].normal = Vector3( 0, 1.0f, 0 );

		this->vertices[30].normal = Vector3( 0, -1.0f, 0 ); //Down
		this->vertices[31].normal = Vector3( 0, -1.0f, 0 );
		this->vertices[32].normal = Vector3( 0, -1.0f, 0 );
		this->vertices[33].normal = Vector3( 0, -1.0f, 0 );
		this->vertices[34].normal = Vector3( 0, -1.0f, 0 );
		this->vertices[35].normal = Vector3( 0, -1.0f, 0 );

		this->vertices[0].uv = Vector2(0.0f, 0.0f);
		this->vertices[1].uv = Vector2(1.0f, 0.0f);
		this->vertices[2].uv = Vector2(1.0f, 1.0f);
		this->vertices[3].uv = Vector2(1.0f, 1.0f);
		this->vertices[4].uv = Vector2(0.0f, 1.0f);
		this->vertices[5].uv = Vector2(0.0f, 0.0f);

		this->vertices[6].uv = Vector2(0.0f, 0.0f);
		this->vertices[7].uv = Vector2(1.0f, 0.0f);;
		this->vertices[8].uv = Vector2(1.0f, 1.0f);
		this->vertices[9].uv = Vector2(1.0f, 1.0f);
		this->vertices[10].uv = Vector2(0.0f, 1.0f);
		this->vertices[11].uv = Vector2(0.0f, 0.0f);

		this->vertices[12].uv = Vector2(0.0f, 0.0f);
		this->vertices[13].uv = Vector2(1.0f, 0.0f);
		this->vertices[14].uv = Vector2(1.0f, 1.0f);
		this->vertices[15].uv = Vector2(1.0f, 1.0f);
		this->vertices[16].uv = Vector2(0.0f, 1.0f);
		this->vertices[17].uv = Vector2(0.0f, 0.0f);

		this->vertices[18].uv = Vector2(0.0f, 0.0f);
		this->vertices[19].uv = Vector2(1.0f, 0.0f);
		this->vertices[20].uv = Vector2(1.0f, 1.0f);
		this->vertices[21].uv = Vector2(1.0f, 1.0f);
		this->vertices[22].uv = Vector2(0.0f, 1.0f);
		this->vertices[23].uv = Vector2(0.0f, 0.0f);

		this->vertices[24].uv = Vector2(0.0f, 0.0f);
		this->vertices[25].uv = Vector2(1.0f, 0.0f);
		this->vertices[26].uv = Vector2(1.0f, 1.0f);
		this->vertices[27].uv = Vector2(1.0f, 1.0f);
		this->vertices[28].uv = Vector2(0.0f, 1.0f);
		this->vertices[29].uv = Vector2(0.0f, 0.0f);

		this->vertices[30].uv = Vector2(0.0f, 0.0f);
		this->vertices[31].uv = Vector2(1.0f, 0.0f);
		this->vertices[32].uv = Vector2(1.0f, 1.0f);
		this->vertices[33].uv = Vector2(1.0f, 1.0f);
		this->vertices[34].uv = Vector2(0.0f, 1.0f);
		this->vertices[35].uv = Vector2(0.0f, 0.0f);

		this->mesh->UpdateVertices(this->vertices, 36);
	}

	void Triangle::update()
	{
		this->shader->BindShader();
		this->shader->SetModelMatrix(this->transform->getModelMatrix());
		if (this->viewCamera != nullptr)
		{
			this->shader->SetViewMatrix(this->viewCamera->getViewMatrix());
			this->shader->SetProjectionMatrix(this->viewCamera->getProjectionMatrix());
		}
		if (LightManager::instance()->sceneLights.size() > 0)
		{
			this->shader->SetUniform_Int("numberOfLights", LightManager::instance()->sceneLights.size());
			this->shader->SetUniform_Float("pointLight.intensity", LightManager::instance()->sceneLights[0]->intensity);
			this->shader->SetUniform_Vec3("pointLight.position" , LightManager::instance()->sceneLights[0]->transform->position.toGLM());
			this->shader->SetUniform_Vec4("pointLight.color", LightManager::instance()->sceneLights[0]->lightColor->toGLM());
		}
		if (this->textures.size() > 0)
		{
			for (size_t i = 0; i < textures.size(); i++)
			{
				this->textures[i]->Bind();
			}
		}
		this->mesh->Draw();
		if (this->textures.size() > 0)
		{
			for (size_t i = 0; i < textures.size(); i++)
			{
				this->textures[i]->Unbind();
			}
		}
		this->shader->UnbindShader();
	}

	void Quad::update()
	{	
		this->shader->BindShader();
		this->shader->SetModelMatrix(this->transform->getModelMatrix());
		if (this->viewCamera != nullptr)
		{
			this->shader->SetViewMatrix(this->viewCamera->getViewMatrix());
			this->shader->SetProjectionMatrix(this->viewCamera->getProjectionMatrix());
		}
		if (this->textures.size() > 0)
		{
			for (size_t  i = 0 ; i < textures.size() ; i++)
			{
				this->textures[i]->Bind();
			}
		}
		if (LightManager::instance()->sceneLights.size() > 0)
		{
			this->shader->SetUniform_Int("numberOfLights", LightManager::instance()->sceneLights.size());
			this->shader->SetUniform_Float("pointLight.intensity", LightManager::instance()->sceneLights[0]->intensity);
			this->shader->SetUniform_Vec3("pointLight.position", LightManager::instance()->sceneLights[0]->transform->position.toGLM());
			this->shader->SetUniform_Vec4("pointLight.color", LightManager::instance()->sceneLights[0]->lightColor->toGLM());
		}
		this->mesh->Draw();
		if (this->textures.size() > 0)
		{
			for (size_t i = 0; i < textures.size(); i++)
			{
				this->textures[i]->Unbind();
			}
		}
		this->shader->UnbindShader();
	}

	void Cube::update() 
	{
		this->shader->BindShader();
		this->shader->SetModelMatrix(this->transform->getModelMatrix());
		if (this->viewCamera != nullptr)
		{
			this->shader->SetViewMatrix(this->viewCamera->getViewMatrix());
			this->shader->SetProjectionMatrix(this->viewCamera->getProjectionMatrix());
		}
		if (this->textures.size() > 0)
		{
			for (size_t i = 0; i < textures.size(); i++)
			{
				this->textures[i]->Bind();
			}
		}
		if (LightManager::instance()->sceneLights.size() > 0)
		{	
			this->shader->SetUniform_Int("numberOfLights",LightManager::instance()->sceneLights.size());
			this->shader->SetUniform_Float("pointLight.intensity", LightManager::instance()->sceneLights[0]->intensity);
			this->shader->SetUniform_Vec3("pointLight.position", LightManager::instance()->sceneLights[0]->transform->position.toGLM());
			this->shader->SetUniform_Vec4("pointLight.color", LightManager::instance()->sceneLights[0]->lightColor->toGLM());
		}
		this->mesh->Draw();
		if (this->textures.size() > 0)
		{
			for (size_t i = 0; i < textures.size(); i++)
			{
				this->textures[i]->Unbind();
			}
		}
		this->shader->UnbindShader();
	}
}


