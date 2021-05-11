#pragma once
// �C���f�b�N�X���g�����}�`�̕`��
#include "ShapeIndex.h"
// �R���X�g���N�^
 // size: ���_�̈ʒu�̎���
 // vertexcount: ���_�̐�
 // vertex: ���_�������i�[�����z��
 // indexcount: ���_�̃C���f�b�N�X�̗v�f��
// �C���f�b�N�X���g�����O�p�`�ɂ��`��
class SolidShapeIndex : public ShapeIndex
{
public:
	//�R���X�g���N�^
	SolidShapeIndex(GLint size, GLsizei vertexcount, const Object::Vertex* vertex,
		GLsizei indexcount, const GLuint* index);


	// �`��̎��s
	virtual void execute() const;
};