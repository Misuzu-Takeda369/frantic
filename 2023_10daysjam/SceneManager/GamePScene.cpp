#include "GamePScene.h"

GamePScene::GamePScene() 
{
	
}

GamePScene::~GamePScene()
{
	delete player_;
}

void GamePScene::Initialize() 
{
	CountNum_ = 0;
	player_ = new Player();
	player_->Initialize();

}

void GamePScene::Update(char* keys, char* preKeys)
{
	switch (gameSModeNow_)
	{
	case None:

		if (!GameMove_) {
			//ここ押すと動き出す
			if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
				GameMove_ = true;
			}
		}
		else {

			player_->Update(keys, preKeys);
		
#pragma region シーン変更含む
			changeTimingFrame_++;
			///ポーズへ
			if((preKeys[DIK_P] == 0 && keys[DIK_P] != 0)&& changeTimingFrame_>=30){
				GameMove_ = false;
				gameSModeNow_ = Pause;
				changeTimingFrame_ = 0;
			}
			//確認用
			CountNum_ += 1;

			///シーン変換
			//ここのif文でシーン移行出来るかを判別
			//現在はIを押したときに移動
			if ((preKeys[DIK_I] == 0 && keys[DIK_I] != 0) && changeTimingFrame_ >= 30) {
				flagChange_ = true;
				changeTimingFrame_ = 0;
			}
			//ここのif文でシーン移行出来るかを判別
			//現在はOを押したときに移動(がめおべ)
			if ((preKeys[DIK_O] == 0 && keys[DIK_O] != 0) && changeTimingFrame_ >= 30) {
				flagChange_ = true;
				flagGameOver_ = true;
				changeTimingFrame_ = 0;
			}
#pragma endregion 
		}
		
		break;

	case Pause:

		changeTimingFrame_++;
		//解除
		if ((preKeys[DIK_P] == 0 && keys[DIK_P] != 0)&& changeTimingFrame_ >= 30) {
			GameMove_ = true;
			gameSModeNow_ = None;
			changeTimingFrame_ = 0;
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


void GamePScene::Draw() 
{
	switch (gameSModeNow_)
	{
	case None:
	
		break;

	default:
		break;
	}

	player_->Draw();
	Novice::ScreenPrintf(500, 500, "%d", CountNum_);
	Novice::ScreenPrintf(500, 550, "%d", changeTimingFrame_);
}
