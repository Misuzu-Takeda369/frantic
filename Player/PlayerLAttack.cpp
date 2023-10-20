#include "PlayerLAttack.h"
#include <cassert>

void PlayerLAttack::Initialize(bool& playerAttackTypeNow, int& maindStateNow, int& playerDirection, Vector2& playerPos)
{
	charaBase_ = {
		{playerPos},{8.0f,0.0f},32.0f,0.0f,RED
	};

	//現在の攻撃type
	playerAttackTypeNow_ = playerAttackTypeNow;
	//現在の狂気度
	maindStateNow_ = maindStateNow;
	//プレイヤーの向き
	playerDirection_ = playerDirection;
}

void PlayerLAttack::Update()
{
	//弾の移動
	if (playerDirection_ == 1) {
		charaBase_.pos_ = { charaBase_.pos_.x + charaBase_.speed_.x,charaBase_.pos_.y + charaBase_.speed_.y };
	}
	else {
		charaBase_.pos_ = { charaBase_.pos_.x - charaBase_.speed_.x,charaBase_.pos_.y - charaBase_.speed_.y };
	}

	//弾が消える(時間経過)
	--deathTimer_;
	if (deathTimer_ <= 0) {
		isDead_ = true;
	}
}

void PlayerLAttack::Draw()
{
	Novice::DrawEllipse(int(charaBase_.pos_.x), int(charaBase_.pos_.y), int(charaBase_.radius_), int(charaBase_.radius_), 0.0f, charaBase_.color, kFillModeSolid);

}
