#include <Novice.h>
#include "SceneManager/SceneManager.h"
#include "ScreenSize.h"


const char kWindowTitle[] = "Frantic";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};


	//シーン管理する奴の初期化
	SceneManager* sceneManager_ = new SceneManager();
	sceneManager_->Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, preKeys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		//更新
		sceneManager_->Update(keys, preKeys);

		
		///
		/// ↑更新処理ここまで
		///

		
		//
		/// ↓描画処理ここから
		///
		//描く
		sceneManager_->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	//デリート
	delete sceneManager_;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
