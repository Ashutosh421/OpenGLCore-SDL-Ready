#pragma once
#include "..\MeshUtils\Mesh.h"

namespace AREngine
{
	class Primitive
	{
	protected:
		Vertex* vertices = nullptr;
		Mesh* mesh = nullptr;
	public:
		Primitive();

		virtual void Draw() = 0;
		virtual void SetShader(std::string , std::string) = 0;

		~Primitive();
	};

	class Triangle: public Primitive
	{
	public:
		Triangle();
		~Triangle();

		void Draw() override;
		void SetShader(std::string , std::string) override;

	private:
		
	};

	class Quad: public Primitive
	{
	public:
		Quad();
		~Quad();

		void Draw() override;
		void SetShader(std::string , std::string) override;

	private:
	
	};
}

