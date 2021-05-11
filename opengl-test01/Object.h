#pragma once
#include <GL/glew.h>
#include <cstddef>
// 図形データ
class Object{
	// 頂点配列オブジェクト名
	GLuint vao;
	// 頂点バッファオブジェクト名
	GLuint vbo;

	// インデックスの頂点バッファオブジェクト
	GLuint ibo;
public:
	// 頂点属性
	struct Vertex
	{
		// 位置
		GLfloat position[3];
		// 色
		GLfloat color[3];
	};
	// コンストラクタ
	// size: 頂点の位置の次元
	// vertexcount: 頂点の数
	// vertex: 頂点属性を格納した配列
 // indexcount: 頂点のインデックスの要素数
 // index: 頂点のインデックスを格納した配列
	Object(GLint size, GLsizei vertexcount, const Vertex* vertex,
		GLsizei indexcount, const GLuint* index);
	// デストラクタ
	virtual ~Object();

private:
	// コピーコンストラクタによるコピー禁止
	Object(const Object& o);
	// 代入によるコピー禁止
	Object& operator=(const Object& o);
public:
	// 頂点配列オブジェクトの結合
	void bind() const;
};