#include "Vector.h"

namespace AREngine {
	
	Vector2::Vector2()
	{
		this->x = 0;
		this->y = 0;
	}

	Vector2::Vector2(float x, float y) 
	{
		this->x = x;
		this->y = y;
	}

	float Vector2::magnitude() {
		return sqrtf((this->x * this->x) + (this->y * this->y));
	}

	const Vector2& Vector2::normalized() {
		float magnitude = this->magnitude();
		this->x /= magnitude;
		this->y /= magnitude;
		return (*this);
	}

	const Vector2 Vector2::operator+(const Vector2& other) {
		Vector2 result(0, 0);
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		return (result);
	}

	const Vector2 Vector2::operator-(const Vector2& other) {
		Vector2 result(0 , 0);
		result.x = this->x - other.x;
		result.y = this->y - other.y;
		return (*this);
	}

	const Vector2 Vector2::operator*(const float& other) {
		this->x *= other;
		this->y *= other;
		return *this;
	}

	const Vector2& Vector2::operator+=(const Vector2& other)
	{
		this->x += other.x;
		this->y += other.y;
		return (*this);
	}

	const Vector2& Vector2::operator-=(const Vector2& other) 
	{
		this->x -= other.x;
		this->y -= other.y;
		return (*this);
	}

	const Vector2& Vector2::operator*=(const float& other) {
		this->x *= other;
		this->y *= other;
		return (*this);
	}

	const Vector2& Vector2::dot(const Vector2& other) {
		
		return (*this);
	}

	const Vector2& Vector2::cross(const Vector2& other) {
	
		return (*this);
	}
	
	std::ostream& operator<<(std::ostream& out , const Vector2& current) {
		out << current.x << " , " << current.y ;
		return out;
	}

	Vector3 Vector3::forward = Vector3( 0 , 0 , 1 );
	Vector3 Vector3::right = Vector3(1, 0, 0);
	Vector3 Vector3::up = Vector3(0, 1, 0);
	Vector3 Vector3::zero = Vector3(0 , 0 , 0);

	Vector3::Vector3()
	{
		this->x = 0;
		this->y = 0;
		this->x = 0;
	}

	Vector3::Vector3(float x, float y,float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float Vector3::magnitude() {
		return sqrtf((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
	}

	const Vector3& Vector3::normalized() {
		float magnitude = this->magnitude();
		this->x /= magnitude;
		this->y /= magnitude;
		this->z /= magnitude;
		return (*this);
	}

	const Vector3 Vector3::operator+(const Vector3& other) {
		Vector3 result(0, 0 , 0);
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		result.z = this->z + other.z;
		return (result);
	}

	const Vector3 Vector3::operator-(const Vector3& other) {
		Vector3 result(0, 0, 0);
		result.x = this->x - other.x;
		result.y = this->y - other.y;
		result.z = this->z - other.z;
		return (*this);
	}

	const Vector3 Vector3::operator*(const float& other) {
		this->x *= other;
		this->y *= other;
		this->z *= other;
		return *this;
	}

	const Vector3& Vector3::operator+=(const Vector3& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		return (*this);
	}

	const Vector3& Vector3::operator-=(const Vector3& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		return (*this);
	}

	const Vector3& Vector3::operator*=(const float& other) {
		this->x *= other;
		this->y *= other;
		this->z *= other;
		return (*this);
	}

	const Vector3& Vector3::dot(const Vector3& other) {

		return (*this);
	}

	const Vector3& Vector3::cross(const Vector3& other) {

		return (*this);
	}

	glm::vec3 Vector3::toGLM() {
		glm::vec3 newVec(this->x , this->y , this->z);
		return newVec;
	}

	std::ostream& operator<<(std::ostream& out, const Vector3& current) {
		out << current.x << " , " << current.y << " , " << current.z;
		return out;
	}


	Vector4::Vector4()
	{
		this->x = 0;
		this->y = 0;
		this->x = 0;
		this->w = 0;
	}

	Vector4::Vector4(float x, float y, float z , float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	float Vector4::magnitude() {
		return sqrtf((this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w));
	}

	const Vector4& Vector4::normalized() {
		float magnitude = this->magnitude();
		this->x /= magnitude;
		this->y /= magnitude;
		this->z /= magnitude;
		this->w /= magnitude;
		return (*this);
	}

	const Vector4 Vector4::operator+(const Vector4& other) {
		Vector4 result(0, 0, 0, 0 );
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		result.z = this->z + other.z;
		result.w = this->w + other.w;
		return (result);
	}

	const Vector4 Vector4::operator-(const Vector4& other) {
		Vector4 result(0, 0, 0 , 0);
		result.x = this->x - other.x;
		result.y = this->y - other.y;
		result.z = this->z - other.z;
		result.w = this->w - other.w;
		return (*this);
	}

	const Vector4 Vector4::operator*(const float& other) {
		this->x *= other;
		this->y *= other;
		this->z *= other;
		this->w *= other;
		return *this;
	}

	const Vector4& Vector4::operator+=(const Vector4& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		this->w += other.w;
		return (*this);
	}

	const Vector4& Vector4::operator-=(const Vector4& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;
		return (*this);
	}

	const Vector4& Vector4::operator*=(const float& other) {
		this->x *= other;
		this->y *= other;
		this->z *= other;
		this->w *= other;
		return (*this);
	}

	const Vector4& Vector4::dot(const Vector4& other) {

		return (*this);
	}

	const Vector4& Vector4::cross(const Vector4& other) {

		return (*this);
	}

	const glm::vec4& Vector4::toGLM() {
		return glm::vec4(this->x , this->y , this->z , this->w);
	}

	std::ostream& operator<<(std::ostream& out, const Vector4& current) {
		out << current.x << " , " << current.y << " , " << current.z << " , " << current.w;
		return out;
	}

}

