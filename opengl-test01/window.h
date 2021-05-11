#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

// �E�B���h�E�֘A�̏���
class Window
{
	// �E�B���h�E�̃n���h��
	GLFWwindow* const window;

	// ���c��
	GLfloat aspect;

	// �E�B���h�E�̃T�C�Y
	GLfloat size[2];

	// ���[���h���W�n�ɑ΂���f�o�C�X���W�n�̊g�嗦
	GLfloat scale;

	// �}�`�̐��K���f�o�C�X���W�n��ł̈ʒu
	GLfloat location[2];

	// �L�[�{�[�h�̏��
	int keyStatus;


public:
	// �R���g���N�^
	Window(int width, int height, const char* title);

	// �f�X�g���N�^
	virtual ~Window();

	// �`�惋�[�v�̌p������
	explicit operator bool() {

		// �E�B���h�E�����K�v���Ȃ���� true ��Ԃ�
		return openwindow();
	}
	bool openwindow();
	// �}�E�X����
	void getMouse();

	// �L�[����
	void getKey();

	// �_�u���o�b�t�@�����O
	void swapBuffers() const;

	// �E�B���h�E�̃T�C�Y�ύX���̏���
	static void resize(GLFWwindow* const window, int width, int height);

	// �}�E�X�z�C�[�����쎞�̏���
	static void wheel(GLFWwindow* const window, double x, double y);

	// �L�[�{�[�h���쎞�̏���
	static void keyboard(GLFWwindow* const window, int key, int scancode, int action, int mods);

	// �E�B���h�E�̃T�C�Y�����o��
	const GLfloat* getSize() const;

	// ���[���h���W�n�ɑ΂���f�o�C�X���W�n�̊g�嗦�����o��
	GLfloat getScale() const;

	// ���c������o��
	GLfloat getAspect() const;

	// �}�E�X�ʒu�����o��
	const GLfloat* getLocation() const;

};