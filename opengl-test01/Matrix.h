#pragma once
#include <algorithm>
#include <GL/glew.h>
#include <cmath>
#include "myvec3.h"

// 変換行列
class Matrix
{
	// 変換行列の要素
	GLfloat matrix[16];
public:
	//　コントラクタ
	Matrix();

	// 配列の内容で初期化するコントラクタ
	//   a: GLfloat 型の 16 要素の配列
	Matrix(const GLfloat* a);

	// 行列の要素を右辺値として参照する
	const GLfloat& operator[](std::size_t i) const
	{
		return matrix[i];
	}

	// 行列の要素を左辺値として参照する
	GLfloat& operator[](std::size_t i) 
	{
		return matrix[i];
	};

	// 変換行列の配列を返す
	const GLfloat* data() const;

	// 単位行列を設定する
	void loadIdentity();
	// ベクトルを入れる
	void setLine(GLint index, vec3 vec);

	// 単位行列を作成する
	static Matrix identity();
	
	// (x,y,z) だけ平行移動する変換行列を作成する
	static Matrix translate(GLfloat x,GLfloat y,GLfloat z);
	static Matrix translate(vec3 vec);

	// (x,y,z) だけ拡大縮小する変換行列を作成する
	static Matrix scale(GLfloat x, GLfloat y, GLfloat z);
	static Matrix scale(vec3 vec);

	// せん断をする変換行列を作成する
	static Matrix shear(GLfloat xy_x, GLfloat xy_y, GLfloat xz_x, GLfloat xz_z, GLfloat yz_y, GLfloat yz_z);
	// (x,y,z) だけ座標軸中心の回転する変換行列を作成する
	//static Matrix Rotation(GLfloat x, GLfloat y, GLfloat z);
	//static Matrix Rotation(vec3 vec);

	// (x,y,z) だけ座標軸中心の回転する変換行列を作成する
	static Matrix rotate(GLfloat a, vec3 vec);
	
	// ビュー変換行列を作成する
	static Matrix lookat(vec3 e, vec3 g, vec3 u);

	// 直交投影変換行列を作成する
	static Matrix orthogonal(GLfloat left, GLfloat right,
		GLfloat bottom, GLfloat top,
		GLfloat zNear, GLfloat zFar);
	// 透視投影変換行列を作成する
	static Matrix frustum(GLfloat left, GLfloat right,
		GLfloat bottom, GLfloat top,
		GLfloat zNear, GLfloat zFar);
	// 画角を指定して透視投影変換行列を作成する
	static Matrix perspective(GLfloat fovy, GLfloat aspect,
		GLfloat zNear, GLfloat zFar);
	Matrix operator*(const Matrix& m)const;
};