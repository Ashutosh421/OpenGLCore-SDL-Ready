#include <iostream>
#include <glm\glm.hpp>
#include <memory>
#include "SEngine\Engine.h"
#include "Utils\Display.h"
#include "Utils\ResourceManager.h"
#include "Utils\Input\Input.h"
#include "SEngine\Camera\Camera.h"
#include "SEngine\Texture\TextureManager.h"
#include "SEngine\Geometry\Geometry.h"
#include "SEngine\Geometry\Cubemap.h"
#include "SEngine\Lighting\LightManager.h"

#define TEST_PRIMITIVE true

using namespace AREngine;

enum GameState
{
	INIT,
	PLAY,
	EXIT
}_gameState;

void init();
void GameLoop();
void Rendering();
void close();

#pragma region Variables
Camera* mainCamera;

Geometry* quad;
Geometry* cube;
Geometry* cube2;


Light* pointLight;

Cubemap* cubemap;

#pragma endregion


void init() 
{	
#pragma region Display_Code
	std::cout << "Initialized the Engine  " << std::endl;
	Engine::instance()->Init();
	_gameState = GameState::INIT;
	Display::instance()->Launch("OpenGL Practice", 1336, 800);
#pragma endregion

#if TEST_PRIMITIVE
	mainCamera = new AREngine::Camera();
	mainCamera->transform->position = Vector3(0 , -1 , -6);

	quad = Geometry::Instantiate(Geometry::GeometryType::QUAD);
	quad->setShader("Assets/Shaders/MVP/Vertex_Shader_MVP.ves", "Assets/Shaders/MVP/Fragment_Shader_MVP.fes");
	quad->setTextureTiling(4, 4);
	quad->SetViewCamera(mainCamera);
	quad->setTexture("Assets/Textures/WallTexture_5.jpg");
	quad->transform->position = Vector3(0, 2, 0);
	quad->transform->eulerAngles = Vector3(90 , 0 , 0);
	quad->transform->scale = Vector3(20 ,10 , 10);

	cube = Geometry::Instantiate(Geometry::GeometryType::CUBE);
	cube->setShader("Assets/Shaders/MVP/Vertex_Shader_MVP.ves", "Assets/Shaders/MVP/Fragment_Shader_MVP.fes");
	cube->SetViewCamera(mainCamera);
	cube->setTexture("Assets/Textures/WallTexture_1.jpg");
	cube->transform->position = Vector3( 0 , 0.8f , -1);

	cube2 = Geometry::Instantiate(Geometry::GeometryType::CUBE);
	cube2->setShader("Assets/Shaders/MVP/Vertex_Shader_MVP.ves", "Assets/Shaders/MVP/Fragment_Shader_MVP.fes");
	cube2->SetViewCamera(mainCamera);
	cube2->setTexture("Assets/Textures/WallTexture_1.jpg");
	cube2->transform->position = Vector3(-2, 0.8f, -1);

	pointLight = LightManager::Instantiate(LightType::POINT_LIGHT);
	pointLight->setViewCamera(mainCamera);
	pointLight->transform->position = Vector3( 0 , -2 , -3);
	pointLight->transform->scale = Vector3(0.2f , 0.2f , 0.2f);
	pointLight->setColor(Color::maroon);
	pointLight->intensity = 4.5f;

	cubemap = new Cubemap("Assets/CubeMaps/JFNuke");
	cubemap->SetViewCamera(mainCamera);
#endif // TEST_PRIMITIVE
}

void GameLoop() 
{
	while (AREngine::Engine::engineStatus != AREngine::EngineStatus::CLOSED)
	{
		Engine::instance()->PollEvents();
		Display::instance()->Clear();

		Rendering();
		
		Display::instance()->Update();
	}
}

int testSpeed = 5;

void Rendering()
{
	cubemap->update();
	
	quad->update();

	cube->update();
	cube2->update();
	cube->transform->Rotate(Vector3( 0 , 30 , 0) * Time::deltaTime);
	mainCamera->update();
	mainCamera->LookAT(Vector3::zero);
	mainCamera->transform->Translate(Vector3(sin(Time::time) * 5 , 0 , cos(Time::time) * 5) * (Time::deltaTime * 0.1));
	
	if (Input::IsKeyDown_Repeat(SDL_SCANCODE_RIGHT))
	{
		pointLight->transform->Translate(Vector3(1, 0, 0) * Time::deltaTime);
	}
	if (Input::IsKeyDown_Repeat(SDL_SCANCODE_LEFT))
	{
		pointLight->transform->Translate(Vector3(-1, 0, 0) * Time::deltaTime);
	}
	if (Input::IsKeyDown_Repeat(SDL_SCANCODE_UP))
	{
		if (Input::IsKeyDown_Repeat(SDL_SCANCODE_LSHIFT))
		{
			pointLight->transform->Translate(Vector3(0, 1, 0) * Time::deltaTime);
		}
		else
		{
			pointLight->transform->Translate(Vector3(0, 0, 1) * Time::deltaTime);
		}
	}
	if (Input::IsKeyDown_Repeat(SDL_SCANCODE_DOWN))
	{
		if (Input::IsKeyDown_Repeat(SDL_SCANCODE_LSHIFT))
		{
			pointLight->transform->Translate(Vector3(0, -1, 0) * Time::deltaTime);
		}
		else
		{
			pointLight->transform->Translate(Vector3(0, 0, -1) * Time::deltaTime);
		}
	}
	

	pointLight->update();
}

void close()
{	
	Display::instance()->Dispose();
	TextureManager::Clean();
	Engine::instance()->Close();
}

int main(int args1 , char* args2[])
{	
	init();
	GameLoop();
	close();

	return 0;
}
