#pragma once
#include <GL/glew.h>
#include <cstddef>
// �}�`�f�[�^
class Object{
	// ���_�z��I�u�W�F�N�g��
	GLuint vao;
	// ���_�o�b�t�@�I�u�W�F�N�g��
	GLuint vbo;

	// �C���f�b�N�X�̒��_�o�b�t�@�I�u�W�F�N�g
	GLuint ibo;
public:
	// ���_����
	struct Vertex
	{
		// �ʒu
		GLfloat position[3];
		// �F
		GLfloat color[3];
	};
	// �R���X�g���N�^
	// size: ���_�̈ʒu�̎���
	// vertexcount: ���_�̐�
	// vertex: ���_�������i�[�����z��
 // indexcount: ���_�̃C���f�b�N�X�̗v�f��
 // index: ���_�̃C���f�b�N�X���i�[�����z��
	Object(GLint size, GLsizei vertexcount, const Vertex* vertex,
		GLsizei indexcount, const GLuint* index);
	// �f�X�g���N�^
	virtual ~Object();

private:
	// �R�s�[�R���X�g���N�^�ɂ��R�s�[�֎~
	Object(const Object& o);
	// ����ɂ��R�s�[�֎~
	Object& operator=(const Object& o);
public:
	// ���_�z��I�u�W�F�N�g�̌���
	void bind() const;
};