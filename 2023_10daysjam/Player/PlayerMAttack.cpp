#include "PlayerMAttack.h"

void PlayerMAttack::Initialize(bool& playerAttackTypeNow, int& maindStateNow, int& playerDirection)
{
	charaBase_ = {
		{-200.0f,-200.0f},{0.0f,0.0f},64.0f,0.0f,RED
	};

	//現在の攻撃type
	playerAttackTypeNow_ = playerAttackTypeNow;
	//現在の狂気度
	maindStateNow_ = maindStateNow;
	//プレイヤーの向き
	playerDirection_ = playerDirection;

	//最終的に判断する攻撃力
	attackPoint_ = 0.0f;
	//攻撃力(magic時　変動あり)
	magicAttackPoint_ = 10.0f;


}

void PlayerMAttack::Update(Vector2& playerPos, int& playerDirection)
{
	if (playerDirection == 1) {
		charaBase_.pos_ = { playerPos.x + ptoA_.x,playerPos.y + ptoA_.y };
	}
	else {
		charaBase_.pos_ = { playerPos.x - ptoA_.x,playerPos.y - ptoA_.y };
	}
	


#pragma region ImGum関連

#ifdef _DEBUG
	ImGui::Begin("Medle");
	ImGui::InputFloat("attackPoint_:", &attackPoint_);
	ImGui::Text("attackMultiples_:%.2f, \n", attackMultiples_);
	ImGui::Text("nomalAttackPoint_:%.2f, \n", nomalAttackPoint_);
	ImGui::InputFloat("magicAttackPoint_:", &magicAttackPoint_);
	ImGui::End();
#endif // DEBUG

}

void PlayerMAttack::Draw()
{
	Novice::DrawEllipse(int(charaBase_.pos_.x), int(charaBase_.pos_.y), int(charaBase_.radius_), int(charaBase_.radius_), 0.0f, charaBase_.color, kFillModeWireFrame);
	Novice::ScreenPrintf(600,600,"attackPoint_:%.2f", attackPoint_);
}

void PlayerMAttack::DeterminingAttackPower(float hp, float maxHp)
{
	if (playerAttackTypeNow_ == 1) {

		if (maindStateNow_ == 0) {
			attackPoint_ = magicAttackPoint_;
		}
		else {
			magicAttackPoint_ +=  ((maxHp - hp) * attackMultiples_);
			attackPoint_ = magicAttackPoint_;
		}

	}
	else {
		attackPoint_ = nomalAttackPoint_;
	}
}
