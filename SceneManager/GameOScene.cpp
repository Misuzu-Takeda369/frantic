#include "GameOScene.h"

GameOScene::GameOScene() {}

GameOScene::~GameOScene() {}


void GameOScene::Initialize() 
{
	
}

void GameOScene::Update(char* keys, char* preKeys)
{
#pragma region シーン変換
	//ここのif文でシーン移行出来るかを判別
	//現在は4を押したときに移動
	changeTimingFrame_++;
	//ここのif文でシーン移行出来るかを判別
	//現在は0を押したときに移動タイトルへ
	if ((preKeys[DIK_I] == 0 && keys[DIK_I] != 0) && changeTimingFrame_ >= 30) {
		flagChange_ = true;
		changeTimingFrame_ = 0;
	}
	//リトライする場合
	else if ((preKeys[DIK_O] == 0 && keys[DIK_O] != 0) && changeTimingFrame_ >= 30) {
		flagChange_ = true;
		flagRetry_ = true;
		changeTimingFrame_ = 0;
	}
#pragma endregion
}

void GameOScene::Draw() {}

