#pragma once
#include <algorithm>
#include <GL/glew.h>
#include <cmath>
#include "myvec3.h"

// �ϊ��s��
class Matrix
{
	// �ϊ��s��̗v�f
	GLfloat matrix[16];
public:
	//�@�R���g���N�^
	Matrix();

	// �z��̓��e�ŏ���������R���g���N�^
	//   a: GLfloat �^�� 16 �v�f�̔z��
	Matrix(const GLfloat* a);

	// �s��̗v�f���E�Ӓl�Ƃ��ĎQ�Ƃ���
	const GLfloat& operator[](std::size_t i) const
	{
		return matrix[i];
	}

	// �s��̗v�f�����Ӓl�Ƃ��ĎQ�Ƃ���
	GLfloat& operator[](std::size_t i) 
	{
		return matrix[i];
	};

	// �ϊ��s��̔z���Ԃ�
	const GLfloat* data() const;

	// �P�ʍs���ݒ肷��
	void loadIdentity();
	// �x�N�g��������
	void setLine(GLint index, vec3 vec);

	// �P�ʍs����쐬����
	static Matrix identity();
	
	// (x,y,z) �������s�ړ�����ϊ��s����쐬����
	static Matrix translate(GLfloat x,GLfloat y,GLfloat z);
	static Matrix translate(vec3 vec);

	// (x,y,z) �����g��k������ϊ��s����쐬����
	static Matrix scale(GLfloat x, GLfloat y, GLfloat z);
	static Matrix scale(vec3 vec);

	// ����f������ϊ��s����쐬����
	static Matrix shear(GLfloat xy_x, GLfloat xy_y, GLfloat xz_x, GLfloat xz_z, GLfloat yz_y, GLfloat yz_z);
	// (x,y,z) �������W�����S�̉�]����ϊ��s����쐬����
	//static Matrix Rotation(GLfloat x, GLfloat y, GLfloat z);
	//static Matrix Rotation(vec3 vec);

	// (x,y,z) �������W�����S�̉�]����ϊ��s����쐬����
	static Matrix rotate(GLfloat a, vec3 vec);
	
	// �r���[�ϊ��s����쐬����
	static Matrix lookat(vec3 e, vec3 g, vec3 u);

	// ���𓊉e�ϊ��s����쐬����
	static Matrix orthogonal(GLfloat left, GLfloat right,
		GLfloat bottom, GLfloat top,
		GLfloat zNear, GLfloat zFar);
	// �������e�ϊ��s����쐬����
	static Matrix frustum(GLfloat left, GLfloat right,
		GLfloat bottom, GLfloat top,
		GLfloat zNear, GLfloat zFar);
	// ��p���w�肵�ē������e�ϊ��s����쐬����
	static Matrix perspective(GLfloat fovy, GLfloat aspect,
		GLfloat zNear, GLfloat zFar);
	Matrix operator*(const Matrix& m)const;
};