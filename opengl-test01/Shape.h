#pragma once
#include <memory>
// �}�`�f�[�^
#include "Object.h"
// �}�`�̕`��
class Shape
{
	// �}�`�f�[�^
	std::shared_ptr<const Object> object;
protected:
	// �`��Ɏg�����_�̐�
	const GLsizei vertexcount;
public:
	// �R���X�g���N�^
	// size: ���_�̈ʒu�̎���
	// vertexcount: ���_�̐�
	// vertex: ���_�������i�[�����z��
 // indexcount: ���_�̃C���f�b�N�X�̗v�f��
 // index: ���_�̃C���f�b�N�X���i�[�����z��
	Shape(GLint size, GLsizei vertexcount, const Object::Vertex* vertex,
		GLsizei indexcount = 0, const GLuint* index = NULL);

	// �`��
	void draw() const;
	// �`��̎��s
	virtual void execute() const;
};