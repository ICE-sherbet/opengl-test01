
#include "Object.h"
// コンストラクタ
// size: 頂点の位置の次元
// vertexcount: 頂点の数
// vertex: 頂点属性を格納した配列
// indexcount: 頂点のインデックスの要素数
// index: 頂点のインデックスを格納した配列
Object::Object(GLint size, GLsizei vertexcount, const Vertex* vertex,
	GLsizei indexcount = 0, const GLuint* index = NULL)
{
	// 頂点配列オブジェクト
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	// 頂点バッファオブジェクト
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,
		vertexcount * sizeof(Vertex), vertex, GL_STATIC_DRAW);
	// 結合されている頂点バッファオブジェクトを in 変数から参照できるようにする
	glVertexAttribPointer(0, size, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		static_cast<Vertex*>(0)->position);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		static_cast<Vertex*>(0)->color);
	glEnableVertexAttribArray(1);

	// インデックスの頂点バッファオブジェクト
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		indexcount * sizeof(GLuint), index, GL_STATIC_DRAW);
}
// デストラクタ
Object::~Object()
{
	// 頂点配列オブジェクトを削除する
	glDeleteVertexArrays(1, &vao);
	// 頂点バッファオブジェクトを削除する
	glDeleteBuffers(1, &vbo);

	// インデックスの頂点バッファオブジェクトを削除する
	glDeleteBuffers(1, &ibo);
}
// 頂点配列オブジェクトの結合
void Object::bind() const
{
	// 描画する頂点配列オブジェクトを指定する
	glBindVertexArray(vao);
}
