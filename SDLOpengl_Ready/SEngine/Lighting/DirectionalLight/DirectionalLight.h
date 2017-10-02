#pragma once
#include "../Light.h"


namespace AREngine {

	class DirectionalLight : public Light
	{
	private:
		Vector3 direction;

	public:
		DirectionalLight();
		~DirectionalLight();
		void update() override;
		inline void setDirection(const Vector3& direction) {
			this->direction = direction;
		}
		inline glm::vec3 getDirection() 
		{
			return this->direction.toGLM();
		}
	};

}



