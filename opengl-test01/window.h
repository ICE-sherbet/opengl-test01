#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

// ウィンドウ関連の処理
class Window
{
	// ウィンドウのハンドル
	GLFWwindow* const window;

	// 横縦比
	GLfloat aspect;

	// ウィンドウのサイズ
	GLfloat size[2];

	// ワールド座標系に対するデバイス座標系の拡大率
	GLfloat scale;

	// 図形の正規化デバイス座標系上での位置
	GLfloat location[2];

	// キーボードの状態
	int keyStatus;


public:
	// コントラクタ
	Window(int width, int height, const char* title);

	// デストラクタ
	virtual ~Window();

	// 描画ループの継続判定
	explicit operator bool() {

		// ウィンドウを閉じる必要がなければ true を返す
		return openwindow();
	}
	bool openwindow();
	// マウス操作
	void getMouse();

	// キー操作
	void getKey();

	// ダブルバッファリング
	void swapBuffers() const;

	// ウィンドウのサイズ変更時の処理
	static void resize(GLFWwindow* const window, int width, int height);

	// マウスホイール操作時の処理
	static void wheel(GLFWwindow* const window, double x, double y);

	// キーボード操作時の処理
	static void keyboard(GLFWwindow* const window, int key, int scancode, int action, int mods);

	// ウィンドウのサイズを取り出す
	const GLfloat* getSize() const;

	// ワールド座標系に対するデバイス座標系の拡大率を取り出す
	GLfloat getScale() const;

	// 横縦比を取り出す
	GLfloat getAspect() const;

	// マウス位置を取り出す
	const GLfloat* getLocation() const;

};