﻿#include "TitleScene.h"

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {}

void TitleScene::Initialize()
{

}

void TitleScene::Update(char* keys, char* preKeys)
{


	switch (titleSModeNow_)
	{
	case None:


		changeTimingFrame_++;
		//ここのif文でシーン移行出来るかを判別
		//現在は1を押したときに移動
		if ((preKeys[DIK_0] == 0 && keys[DIK_0] != 0)&& changeTimingFrame_>= 60) {
			flagChange_ = true;
			changeTimingFrame_ = 0;
		}

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

}


