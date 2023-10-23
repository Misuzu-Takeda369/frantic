#include "HpUI.h"

void HpUI::Initialize()
{
	//左上端
	Lpos_ = { 50,20 };
	//右下端
	Rpos_ = { sizeX_,sizeY_ };
	//画像
	image_ = Novice::LoadTexture("./Resources/images/HPBar_kari.png");
	
	//移動した合計
	moveX_ = 0;
	//移動する量(HPが1たび増減するたびに動く量)
	moveSpeedX_ = 1;
}

void HpUI::Update(float hp,float maxhp)
{
	
	int decreaseHp = int(maxhp - hp);
	moveX_ = (moveSpeedX_) *decreaseHp;
	
}


void HpUI::Draw()
{
	//決まった範囲に画像写すタイプ
	//Novice::DrawSpriteRect();
	//画像写す範囲を徐々に狭めていくタイプ
	Novice::DrawQuad(Lpos_.x_, Lpos_.y_, (Lpos_.x_+Rpos_.x_)- moveX_, Lpos_.y_, Lpos_.x_, Lpos_.y_ + Rpos_.y_, (Lpos_.x_ + Rpos_.x_) - moveX_, Lpos_.y_ + Rpos_.y_
	,0,0, sizeX_, sizeY_, image_,WHITE);
}
