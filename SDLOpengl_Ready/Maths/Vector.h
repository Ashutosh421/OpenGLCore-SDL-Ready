#pragma once
#include <iostream>
#include <ostream>
#include <glm\glm.hpp>

namespace AREngine {
	struct Vector2
	{
		float x;
		float y;

		Vector2();

		Vector2(float , float);

		float magnitude();

		const Vector2& normalized();

		const Vector2 operator+(const Vector2& other);

		const Vector2 operator-(const Vector2& other);

		const Vector2 operator*(const float& other);

		const Vector2& operator+=(const Vector2& other);

		const Vector2& operator-=(const Vector2& other);

		const Vector2& operator*=(const float& other);

		const Vector2& dot(const Vector2& other);

		const Vector2& cross(const Vector2& other);

		friend std::ostream& operator<<(std::ostream& out, const Vector2& current);
	};

	struct Vector3
	{
		float x;
		float y;
		float z;

		static Vector3 zero;
		static Vector3 up;
		static Vector3 right;
		static Vector3 forward;

		Vector3();

		Vector3(float, float , float);

		float magnitude();

		const Vector3& normalized();

		const Vector3 operator+(const Vector3& other);

		const Vector3 operator-(const Vector3& other);

		const Vector3 operator*(const float& other);

		const Vector3& operator+=(const Vector3& other);

		const Vector3& operator-=(const Vector3& other);

		const Vector3& operator*=(const float& other);

		const Vector3& dot(const Vector3& other);

		const Vector3& cross(const Vector3& other);

		glm::vec3 toGLM();

		friend std::ostream& operator<<(std::ostream& out, const Vector3& current);
	};

	struct Vector4
	{
		float x;
		float y;
		float z;
		float w;

		Vector4();

		Vector4(float, float, float, float);

		float magnitude();

		const Vector4& normalized();

		const Vector4 operator+(const Vector4& other);

		const Vector4 operator-(const Vector4& other);

		const Vector4 operator*(const float& other);

		const Vector4& operator+=(const Vector4& other);

		const Vector4& operator-=(const Vector4& other);

		const Vector4& operator*=(const float& other);

		const Vector4& dot(const Vector4& other);

		const Vector4& cross(const Vector4& other);

		const glm::vec4& toGLM();

		friend std::ostream& operator<<(std::ostream& out, const Vector4& current);
	};
}