#pragma once
#include "../Entity/Entity.h"
#include "../Time/Time.h"
#include "../Lighting/LightManager.h"

namespace AREngine {

	class Geometry : public Entity
	{
	private:
	//	Texture* texture;

	public:
		Geometry() = default;
		~Geometry() = default;

		enum GeometryType {
			TRIANGLE,
			QUAD,
			CUBE
		};

		virtual void update() override = 0;
		void setShader(std::string, std::string) override;
		void setTexture(std::string) override;
		static Geometry* Instantiate(GeometryType geometry);
	};

	class Triangle : public Geometry
	{
	public:
		Triangle();
		~Triangle();
		void update() override;


	private:
	
	};

	class Quad : public Geometry
	{
	public:
		Quad();
		~Quad();

		void update() override;

	private:

	};

	class Cube : public Geometry
	{
	public:
		Cube();
		~Cube();

		void update() override;

	private:

	};
}



