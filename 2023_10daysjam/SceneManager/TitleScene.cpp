﻿#include "TitleScene.h"

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {}

void TitleScene::Initialize()
{
	titleImage_ = Novice::LoadTexture("./Resources/images/Text/Title_kari.png");
	startImage_ = Novice::LoadTexture("./Resources/images/Text/Start_kari.png");

	startPos_ = {
		450,350
	};
	startColor_ = { 255,255,255,255,0xFFFFFFFF };
}

void TitleScene::Update(char* keys, char* preKeys)
{
	keys; preKeys;

	switch (titleSModeNow_)
	{
	case None:


		changeTimingFrame_++;
		//ここのif文でシーン移行出来るかを判別
		
		//マウスでのシーン移動
		MouseBottonChack();

#ifdef _DEBUG
		//現在は1を押したときに移動
		if ((preKeys[DIK_I] == 0 && keys[DIK_I] != 0)&& changeTimingFrame_>= 60) {
			flagChange_ = true;
			changeTimingFrame_ = 0;
		}

#endif // _DEBUG
		break;

	case Expriense:

		break;
		/*今は多分いらん
			case Option:
				break;*/
	default:
		break;
	}
}

void TitleScene::Draw()
{
	//背景‽の色
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x30182CFF, kFillModeSolid);
	//タイトル
	Novice::DrawSprite(250,50, titleImage_,1.0f,1.0f,0.0f,WHITE);
	//文字の奴
	Novice::DrawSprite(startPos_.x_, startPos_.y_, startImage_, 1.0f, 1.0f, 0.0f, startColor_.color);
}

void TitleScene::MouseBottonChack()
{
	Novice::GetMousePosition(&mousePos_.x_, &mousePos_.y_);


	if ((mousePos_.x_>= startPos_.x_ && mousePos_.x_ <= startPos_.x_+ startSizeX_)
		&&
		(mousePos_.y_ >= startPos_.y_ && mousePos_.y_ <= startPos_.y_ + startSizeY_))
	{
		startColor_.color = RED;
		//はじめるに入っている場合左クリックするとスターとする
		if (Novice::IsTriggerMouse(0) && changeTimingFrame_ >= 60) {
			flagChange_ = true;
			changeTimingFrame_ = 0;
		}
	}
	else {
		startColor_.color = WHITE;
	}
}


