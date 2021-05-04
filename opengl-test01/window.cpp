#include "window.h"

// �R���g���N�^
Window::Window(int width = 640, int height = 480, const char* title = "Hello!")
	: window(glfwCreateWindow(width, height, title, NULL, NULL))
	, scale(100.0f), location{ 0.0f,0.0f }
{
	if (window == NULL) {
		// �E�B���h�E���쐬�ł��Ȃ�����
		cerr << "Can't create GLFW window." << endl;
		exit(1);
	}
	// ���݂̃E�B���h�E�������Ώۂɂ���
	glfwMakeContextCurrent(window);

	// GLFW ������������
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		// GLEW �̏������Ɏ��s����
		cerr << "Can't initialize GLEW." << endl;
		exit(1);

	}
	// ���������̃^�C�~���O��҂�
	glfwSwapInterval(1);

	// ���̃C���X�^���X�� this �|�C���^���L�^���Ă���
	glfwSetWindowUserPointer(window, this);

	// �E�B���h�E�̃T�C�Y�ύX���ɌĂяo�������̓o�^
	glfwSetFramebufferSizeCallback(window, resize);

	// �J�����E�B���h�E�̏����ݒ�
	resize(window, width, height);

}

// �f�X�g���N�^
Window::~Window() {
	glfwDestroyWindow(window);
}


// �`�惋�[�v�̌p������
bool Window::openwindow() {
	// �C�x���g�����o��
	glfwWaitEvents();

	// �E�B���h�E�����K�v���Ȃ���� true ��Ԃ�
	return !glfwWindowShouldClose(window);

}

// �_�u���o�b�t�@�����O
void Window::swapBuffers() const {
	// �J���[�o�b�t�@�����ւ���
	glfwSwapBuffers(window);
}

// �E�B���h�E�̃T�C�Y�ύX���̏���
void Window::resize(GLFWwindow* const window, int width, int height) {
	// �t���[���o�b�t�@�̃T�C�Y�𒲂ׂ�
	int fbWidth, fbHeight;
	glfwGetFramebufferSize(window, &fbWidth, &fbHeight);

	// �t���[���o�b�t�@�S�̂��r���[�|�[�g�ɐݒ肷��
	glViewport(0, 0, fbWidth, fbHeight);

	// ���̃C���X�^���X�� this �|�C���^�𓾂�
	Window* const
		instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));

	if (instance != NULL) {
		// ���̃C���X�^���X���ێ����鉡�c����X�V����
		instance->aspect =
			static_cast<GLfloat>(width) / static_cast<GLfloat>(height);
		// �E�B���h�E�̃T�C�Y��ۑ�����
		instance->size[0] = static_cast<GLfloat>(width);
		instance->size[1] = static_cast<GLfloat>(height);
	}


}

// �E�B���h�E�̃T�C�Y�����o��
const GLfloat* Window::getSize() const { return size; }

// ���[���h���W�n�ɑ΂���f�o�C�X���W�n�̊g�嗦�����o��
GLfloat Window::getScale() const { return scale; }

GLfloat Window::getAspect() const { return aspect; }