#include "window.h"

// コントラクタ
Window::Window(int width = 640, int height = 480, const char* title = "Hello!")
	: window(glfwCreateWindow(width, height, title, NULL, NULL))
	, scale(100.0f), location{ 0.0f,0.0f }
{
	if (window == NULL) {
		// ウィンドウが作成できなかった
		cerr << "Can't create GLFW window." << endl;
		exit(1);
	}
	// 現在のウィンドウを処理対象にする
	glfwMakeContextCurrent(window);

	// GLFW を初期化する
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		// GLEW の初期化に失敗した
		cerr << "Can't initialize GLEW." << endl;
		exit(1);

	}
	// 垂直同期のタイミングを待つ
	glfwSwapInterval(1);

	// このインスタンスの this ポインタを記録しておく
	glfwSetWindowUserPointer(window, this);

	// ウィンドウのサイズ変更時に呼び出す処理の登録
	glfwSetFramebufferSizeCallback(window, resize);

	// 開いたウィンドウの初期設定
	resize(window, width, height);

}

// デストラクタ
Window::~Window() {
	glfwDestroyWindow(window);
}


// 描画ループの継続判定
bool Window::openwindow() {
	// イベントを取り出す
	glfwWaitEvents();

	// ウィンドウを閉じる必要がなければ true を返す
	return !glfwWindowShouldClose(window);

}

// ダブルバッファリング
void Window::swapBuffers() const {
	// カラーバッファを入れ替える
	glfwSwapBuffers(window);
}

// ウィンドウのサイズ変更時の処理
void Window::resize(GLFWwindow* const window, int width, int height) {
	// フレームバッファのサイズを調べる
	int fbWidth, fbHeight;
	glfwGetFramebufferSize(window, &fbWidth, &fbHeight);

	// フレームバッファ全体をビューポートに設定する
	glViewport(0, 0, fbWidth, fbHeight);

	// このインスタンスの this ポインタを得る
	Window* const
		instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));

	if (instance != NULL) {
		// このインスタンスが保持する横縦比を更新する
		instance->aspect =
			static_cast<GLfloat>(width) / static_cast<GLfloat>(height);
		// ウィンドウのサイズを保存する
		instance->size[0] = static_cast<GLfloat>(width);
		instance->size[1] = static_cast<GLfloat>(height);
	}


}

// ウィンドウのサイズを取り出す
const GLfloat* Window::getSize() const { return size; }

// ワールド座標系に対するデバイス座標系の拡大率を取り出す
GLfloat Window::getScale() const { return scale; }

GLfloat Window::getAspect() const { return aspect; }