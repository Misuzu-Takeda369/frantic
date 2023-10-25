﻿#include "SpUI.h"

void SpUI::Initialize()
{
	//左上端
	Lpos_ = { 50,100 };
	//右下端
	Rpos_ = { sizeX_,sizeY_ };
	//画像
	image_ = Novice::LoadTexture("./Resources/images/HPBar_kari.png");

	//移動した合計
	moveX_ = 0;
	//移動する量(HPが1たび増減するたびに動く量)
	moveSpeedX_ = 1;
}

void SpUI::Update(float decreasedSp)
{

	int decreaseSp = int(decreasedSp);
	moveX_ = (moveSpeedX_)*decreaseSp;

}


void SpUI::Draw()
{
	//決まった範囲に画像写すタイプ
	Novice::DrawSpriteRect(Lpos_.x_, Lpos_.y_, 0 + moveX_, 0, sizeX_, sizeY_, image_, ((float)500 / 1000), 0.5, 0, WHITE);
	//画像写す範囲を徐々に狭めていくタイプ
	//Novice::DrawQuad(Lpos_.x_, Lpos_.y_, (Lpos_.x_ + Rpos_.x_) - moveX_, Lpos_.y_, Lpos_.x_, Lpos_.y_ + Rpos_.y_, (Lpos_.x_ + Rpos_.x_) - moveX_, Lpos_.y_ + Rpos_.y_
		//, 0, 0, sizeX_, sizeY_, image_, WHITE);
}
