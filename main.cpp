#include <Novice.h>
#include "InputManeger.h"
#include "SceneManeger.h"

const char kWindowTitle[] = "LC1A_04_オオハラアオイ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 800);

	InputManeger* inputManeger = InputManeger::GetInstance();

	SceneManeger sceneManeger;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		///
		/// ↓更新処理ここから
		///

		inputManeger->Update();

		sceneManeger.Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
