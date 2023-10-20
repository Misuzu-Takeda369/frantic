#include "GamePScene.h"

GamePScene::GamePScene() {}

GamePScene::~GamePScene() { delete player_; }

void GamePScene::Initialize() {
	CountNum_ = 0;
	player_ = new Player();
	player_->Initialize();

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
}

void GamePScene::Update() {
	switch (gameSModeNow_) {
	case None:

		if (!GameMove_) {
			// ここ押すと動き出す
			if (input_->TriggerKey(DIK_SPACE)) {
				GameMove_ = true;
			}
		} 
		else {

			player_->Update();

#pragma region シーン変更含む

			if (input_->TriggerKey(DIK_P)) {
				GameMove_ = false;
				gameSModeNow_ = Pause;
			}
			// 確認用
			CountNum_ += 1;

			/// シーン変換
			// ここのif文でシーン移行出来るかを判別
			// 現在は1を押したときに移動
			if (input_->TriggerKey(DIK_I)) {
				flagChange_ = true;
			}
			// ここのif文でシーン移行出来るかを判別
			// 現在は3を押したときに移動(がめおべ)
			if (input_->TriggerKey(DIK_O)) {
				flagChange_ = true;
				flagGameOver_ = true;
			}
#pragma endregion

		}

		break;

	case Pause:

		// 解除
		if (input_->TriggerKey(DIK_P)) {
			GameMove_ = true;
			gameSModeNow_ = None;
		}

		break;

	default:
		break;
	}

#ifdef _DEBUG
#pragma region ImGui関連

	ImGui::Begin("GameMove&Mode");
	ImGui::Text("GameMove_ %d\n0_Stop Butten[DIK_SPACE]\n", GameMove_);
	ImGui::Text("gameSModeNow_ %d\n0_None 1_Pause Butten[DIK_P]\n", gameSModeNow_);
	ImGui::End();

#pragma endregion
#endif // DEBUG
}

void GamePScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();
#pragma region スプライト描画
	// スプライト描画前処理
	Sprite::PreDraw(commandList);

	player_->Draw();

	switch (gameSModeNow_) {
	case None:

		break;

	default:
		break;
	}

	// Novice::ScreenPrintf(500, 500, "%d", CountNum_);
	// Novice::ScreenPrintf(500, 550, "%d", changeTimingFrame_);

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion

}
