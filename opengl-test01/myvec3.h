#pragma once
#include <iostream>
#include <GL/glew.h>


struct vec3{

	float x, y, z;
	vec3();
	// x,y,zで初期化するコントラクタ
	vec3(GLfloat _x, GLfloat _y, GLfloat _z);
	// ベクトルの長さ
	GLfloat length() const;
	GLfloat lengthSquare() const;
	// 要素の合計
	GLfloat sum() const;
	// 外積
	vec3 cross(const vec3& other) const;
	// 内積
	GLfloat	dot(const vec3& other) const;
	// 要素をずらす
	vec3 roll() const;
	//逆ベクトル
	vec3 inverse() const;

	// 2項
	vec3 operator/(GLfloat s) const;
	vec3 operator*(GLfloat s) const;
	vec3 operator+(vec3 other) const;
	vec3 operator-(vec3 other) const;
	// 単項
	vec3 operator+() const;
	vec3 operator-() const;
	// アダマール積
	vec3 operator*(vec3 other) const;

	bool isZero() const;
	bool isNonZero() const;

	static const vec3 ZERO;
	static const vec3 ONE;
	static const vec3 RIGHT;
	static const vec3 UP;
	static const vec3 FORWARD;
};