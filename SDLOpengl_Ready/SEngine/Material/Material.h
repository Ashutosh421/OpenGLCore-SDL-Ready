#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "..\..\Maths\Vector.h"
#include "..\..\Maths\Color.h"

namespace AREngine {

	class Material
	{
	private:
		Color ambience;
		Color diffuse;
		Color specular;

	public:

		float ambienceStrength;
		float diffuseStrength;
		float specularStrength;

		void setAmbience(const Color&);
		void setDiffuse(const Color&);
		void setSpecular(const Color&);

		Color getAmbience();
		Color getDiffuse();
		Color getSpecular();

		void setAmbienceStrength(const float&);
		void setDiffuseStrength(const float&);
		void setSpecularStrength(const float&);
			
		float getAmbienceStrength();
		float getDiffuseStrength();
		float getSpecularStrength();

		Material();
		~Material();
	};

}


