#include <iostream>
#include <glm\glm.hpp>
#include "SEngine\Engine.h"
#include "Utils\Display.h"
#include "Utils\MeshUtils\Vertex.h"
#include "Utils\ResourceManager.h"
#include "Utils\Shader\Shader.h"
#include "Utils\MeshUtils\Mesh.h"
#include "Utils\Primitives\Primitive.h"

#define TEST_MESH false

#define TEST_PRIMITIVE true

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

AREngine::Display* mainDisplay;
AREngine::Mesh* mesh;
AREngine::Primitive* triangle;
AREngine::Primitive* quad;

#pragma endregion


void init() 
{
#pragma region Display_Code
	std::cout << "Initialized the Engine  " << std::endl;
	AREngine::Engine::Init();
	_gameState = GameState::INIT;

	mainDisplay = new AREngine::Display("OpenGL Practice", 1024, 768);
#pragma endregion

#if TEST_MESH
	AREngine::Vertex vertices[3];
	vertices[0].position = glm::vec3(- 0.5f , -0.5f , 0);
	vertices[1].position = glm::vec3(  0.5f , -0.5f , 0);
	vertices[2].position = glm::vec3(  0.0f ,  0.5f , 0);

	vertices[0].color = glm::vec4( 1.0f , 0.0f , 0.0f , 1.0f);
	vertices[1].color = glm::vec4( 0.0f , 1.0f , 0.0f, 1.0f);
	vertices[2].color = glm::vec4( 0.0f , 0.0f , 1.0f, 1.0f);

	mesh = new AREngine::Mesh(vertices, 3);
	mesh->SetShader("Assets/Shaders/Vertex_Shader.ves", "Assets/Shaders/Fragment_Shader.fes");

#endif

#if TEST_PRIMITIVE
	triangle = new AREngine::Triangle();
	quad = new AREngine::Quad();
	quad->SetShader("Assets/Shaders/Vertex_Shader.ves","Assets/Shaders/Fragment_Shader.fes");
#endif // TEST_PRIMITIVE

}

void GameLoop() 
{
	while (AREngine::Engine::engineStatus != AREngine::EngineStatus::CLOSED)
	{
		AREngine::Engine::PollEvents();
		mainDisplay->Clear(); //Clear GL Screen and Color and Depth Buffer Bits
		
		Rendering();
		
		mainDisplay->Update();
	}
}

void Rendering()
{
#if TEST_MESH
	mesh->Draw();
#endif // DEBUG

#if TEST_PRIMITIVE
//	triangle->Draw();
	quad->Draw();
#endif
}

void close()
{
	delete mainDisplay;

	AREngine::Engine::Close();
}

int main(int args1 , char* args2[])
{
	std::cout << "Main Function " << std::endl;
	init();
	GameLoop();
	close();

	return 0;
}
