#pragma once
#include <iostream>
#include <GL/glew.h>


struct vec3{

	float x, y, z;
	vec3();
	// x,y,z�ŏ���������R���g���N�^
	vec3(GLfloat _x, GLfloat _y, GLfloat _z);
	// �x�N�g���̒���
	GLfloat length() const;
	GLfloat lengthSquare() const;
	// �v�f�̍��v
	GLfloat sum() const;
	// �O��
	vec3 cross(const vec3& other) const;
	// ����
	GLfloat	dot(const vec3& other) const;
	// �v�f�����炷
	vec3 roll() const;
	//�t�x�N�g��
	vec3 inverse() const;

	// 2��
	vec3 operator/(GLfloat s) const;
	vec3 operator*(GLfloat s) const;
	vec3 operator+(vec3 other) const;
	vec3 operator-(vec3 other) const;
	// �P��
	vec3 operator+() const;
	vec3 operator-() const;
	// �A�_�}�[����
	vec3 operator*(vec3 other) const;

	bool isZero() const;
	bool isNonZero() const;

	static const vec3 ZERO;
	static const vec3 ONE;
	static const vec3 RIGHT;
	static const vec3 UP;
	static const vec3 FORWARD;
};