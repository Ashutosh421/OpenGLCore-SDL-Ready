#pragma once
#include <iostream>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

namespace AREngine
{
	struct Color
	{
		float r;
		float g;
		float b;
		float a;

		static Color red;
		static Color blue;
		static Color lime;
		static Color white;
		static Color black;
		static Color yellow;
		static Color cyan;
		static Color magenta;
		static Color grey;
		static Color maroon;
		static Color olive;
		static Color green;
		static Color purple;
		static Color teal;
		static Color navy;

		Color(float, float, float, float);

		Color();

		const Color& operator += (const Color& other);

		const Color operator + (const Color& other);

		const Color& operator -= (const Color& other);

		const Color operator - (const Color& other);

		const Color& operator * (const float& other);

		const Color& operator * (const Color& other);

		const glm::vec4 toGLM();

		friend std::ostream& operator<< (std::ostream& , const Color&);
	};
}


