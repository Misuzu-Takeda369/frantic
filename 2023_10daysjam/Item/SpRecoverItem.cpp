#include "SpRecoverItem.h"

void SpRecoverItem::Initialize()
{
	//多分敵のドロップか時間経過か
	charaBase_.pos_ = {500.0f,300.0f};
	//画像サイズ
	sizeX_ = 32; sizeY_ = 32;
	image_= 0;

	//実際に回復する量
	recoverSp_ = recoveryAmount_;
	//ラインが下がる量
	downLineLunatic_ = downLineLunaticAmount_;
}

void SpRecoverItem::Update()
{
	//アイテムが消える(時間経過)
	/*
	--deathTimer_;
	if (deathTimer_ <= 0) {
		isDead_ = true;
	}
	*/

}

void SpRecoverItem::Draw()
{
	//Novice::DrawEllipse(int(charaBase_.pos_.x), int(charaBase_.pos_.y), sizeX_, sizeY_,0.0f,RED,kFillModeSolid);
	Novice::DrawEllipse(100,600, sizeX_, sizeY_, 0.0f, RED, kFillModeSolid);
}
