#include "SceneManager/GameCScene.h"

GameCScene::GameCScene() {}

GameCScene::~GameCScene() {}

void GameCScene::Initialize()
{
}

void GameCScene::Update(char* keys, char* preKeys)
{


	//ここのif文でシーン移行出来るかを判別
	//現在は4を押したときに移動
	changeTimingFrame_++;
	//ここのif文でシーン移行出来るかを判別
	//現在は1を押したときに移動
	if ((preKeys[DIK_I] == 0 && keys[DIK_I] != 0) && changeTimingFrame_ >= 30) {
		flagChange_ = true;
		changeTimingFrame_ = 0;
	}

}

void GameCScene::Draw() {}

void GameCScene::BackDraw() {}
