#include "myvec3.h"

vec3::vec3() :x(0.0f), y(0.0f), z(0.0f) {};
// x,y,zで初期化するコントラクタ
vec3::vec3(GLfloat _x, GLfloat _y, GLfloat _z)
	: x(_x)
	, y(_y)
	, z(_z) {}

GLfloat vec3::length() const {
	return std::sqrt(lengthSquare());
}
GLfloat vec3::lengthSquare() const {
	return dot(*this);
}
GLfloat vec3::sum() const {
	return x + y + z;
}
vec3 vec3::roll() const {
	return { z,x,y };
}
vec3 vec3::cross(const vec3& other) const {
	return { y*other.z - z*other.y,z * other.y - x * other.z,x * other.y - y * other.x };
}
GLfloat vec3::dot(const vec3& other) const {
	return x*other.x+y*other.y+z*other.z;
}
vec3 vec3::inverse() const {
	return { -x,-y,-z };
}

// 2項
vec3 vec3::operator/(GLfloat s) const {
	return { x / s,y / s,z / s };
}
vec3 vec3::operator*(GLfloat s) const {
	return { x * s,y * s,z * s };
}
vec3 vec3::operator+(vec3 other) const {
	return { x + other.x, y + other.y, z + other.z };
}
vec3 vec3::operator-(vec3 other) const {
	return { x - other.x, y - other.y, z - other.z };
}

// 単項
vec3 vec3::operator+() const {
	return *this;
}
vec3 vec3::operator-() const {
	return { -x,-y,-z };
}
// アダマール積
vec3 vec3::operator*(vec3 other) const {
	return { x * other.x, y * other.y, z * other.z };
}


bool vec3::isZero() const {
	return x == 0.0f && y == 0.0f && z == 0.0f;
}
bool vec3::isNonZero() const {
	return x != 0.0f && y!= 0.0f && z != 0.0f;
}

const vec3 vec3::ZERO(0.0f, 0.0f, 0.0f);
const vec3 vec3::ONE(1.0f, 1.0f, 1.0f);
const vec3 vec3::RIGHT(1.0f, 0.0f, 0.0f);
const vec3 vec3::UP(0.0f,1.0f,0.0f);
const vec3 vec3::FORWARD(0.0f,0.0f,1.0f);