#pragma once
#include "../../Maths/Vector.h"
#include "../../Maths/Color.h"
#include "../Transform/Transform.h"
#include "../MeshUtils/Mesh.h"
#include "../Shader/Shader.h"
#include "../Camera/Camera.h"

namespace AREngine 
{
	enum class LightType
	{
		DIRECTIONAL_LIGHT,
		POINT_LIGHT,
		SPOT_LIGHT,
		AREA_LIGHT
	};

	class Light
	{
	private:
		Vertex* vertices;
		void setLightVertices();

	protected:
		Mesh* mesh;
		Camera* viewCamera;

		Vector3 ambience;
		Vector3 diffuse;
		Vector3 specular;
		float specularStrength;

	public:
		float intensity = 1.0f;
		Color* lightColor;
		Shader* shader;
		Transform* transform;
		Light();
		~Light();

		void setColor(const Color&);
		void setViewCamera(Camera*);
		virtual void update() = 0;
	};
}





