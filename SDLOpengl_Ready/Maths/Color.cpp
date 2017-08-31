#include "Color.h"

namespace AREngine
{
	Color Color::black = Color( 0.0f , 0.0f , 0.0f , 0.0f);
	Color Color::white = Color( 1.0f , 1.0f , 1.0f , 1.0f);
	Color Color::red = Color( 1.0f , 0.0f , 0.0f , 1.0f);
	Color Color::blue = Color( 0.0f , 1.0f , 0.0f , 1.0f);
	Color Color::lime = Color( 0.0f , 0.0f , 1.0f , 1.0f);
	Color Color::yellow = Color(1.0f , 1.0f , 0.0f , 1.0f);
	Color Color::cyan = Color (0.0f , 1.0f , 1.0f , 1.0f);
	Color Color::magenta = Color( 1.0f , 0.0f , 1.0f , 1.0f);
	Color Color::grey = Color(0.5f , 0.5f , 0.5f , 1.0f);
	Color Color::maroon = Color(0.5f , 0.0f , 0.0f , 1.0f);
	Color Color::olive = Color(0.5f , 0.5f, 0.0f , 1.0f);
	Color Color::green = Color(0.0f , 0.5f , 0.0f , 1.0f);
	Color Color::purple = Color(0.5f , 0.0f , 0.5f , 1.0f);
	Color Color::teal = Color(0.0f , 0.5f , 0.5f , 1.0f);
	Color Color::navy = Color(0.0f , 0.0f , 0.5f , 1.0f);
		
	Color::Color():r(1), b(1) , g(1), a(1) {}

	Color::Color(float r, float b, float g, float a) :r(r), b(b), g(g), a(a)
	{}

	const Color& Color::operator+= (const Color& other)
	{
		this->r += other.r;
		this->g += other.g;
		this->b += other.b;
		this->a += other.a;
		return *this;
	}

	const Color Color::operator+ (const Color& other) {
		Color newColor(1 , 1 , 1 , 1);
		newColor.r = this->r + other.r;
		newColor.g = this->g + other.g;
		newColor.b = this->b + other.b;
		newColor.a = this->a + other.a;
		return newColor;
	}

	const Color& Color::operator-= (const Color& other)
	{
		this->r -= other.r;
		this->g -= other.g;
		this->b -= other.b;
		this->a -= other.a;
		return *this;
	}

	const Color Color::operator- (const Color& other) 
	{
		Color newColor(1, 1, 1, 1);
		newColor.r = this->r - other.r;
		newColor.g = this->g - other.g;
		newColor.b = this->b - other.b;
		newColor.a = this->a - other.a;
		return newColor;
	}

	const Color& Color::operator* (const float& other) {
		this->r *= other;
		this->g *= other;
		this->b *= other;
		this->a *= other;
		return *this;
	}

	const Color& Color::operator* (const Color& other) {
		this->r *= other.r;
		this->g *= other.g;
		this->b *= other.b;
		this->a *= other.a;
		return *this;
	}

	const glm::vec4 Color::toGLM() {
		return glm::vec4(this->r , this->g , this->b , this->a);
	}

	std::ostream& operator<< (std::ostream& out , const Color& other) {
		out << other.r << " , " << other.g << " , " << other.b << " , " << other.a;
		return out;
	}
}
