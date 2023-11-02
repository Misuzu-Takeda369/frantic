#include "PopEnemy.h"
#include "Novice.h"
#include "ImGuiManager.h"



PopEnemy::~PopEnemy()
{
	//delete E_Bullet;
	delete nEnemy_;
}

void PopEnemy::Initialize()
{
	
	charaBase_.pos_ = { 1400.f,550.0f};
	charaBase_.speed_ = {3.0f,0.3f};
	charaBase_.radius_ = 50;
	

	countEnemy_ = 0;
	//rumNum_ = 1;
	//enemyType_ = NOMAL;

	collisionType_ = Circle;
	


#pragma region ポップした時の判別
	rumNum_ = RandomRange(1, 1);
	if (rumNum_ == 1) {
		enemyType_ = NOMAL;
	}
	else if (rumNum_ == 2) {
		enemyType_ = BULLET;
	}

	switch (enemyType_)
	{
	case NOMAL:

		nEnemy_ = new NEnemy();
		nEnemy_->Initialize(charaBase_.pos_, charaBase_.speed_, charaBase_.radius_);

		break;

	case BULLET:

		break;

	default:
		break;
	}
#pragma endregion

}

void PopEnemy::Update()
{

	switch (enemyType_)
	{
	case NOMAL:
		nEnemy_->Update();

		charaBase_.pos_.x = nEnemy_->GetPosX();
		charaBase_.pos_.y = nEnemy_->GetPosY();

		//ここがゲームシーンにこの個体が消滅している伝えるよう
		if (nEnemy_->GetIsDead()) {
			isDead_ = true;
		}

		break;

	case BULLET:

		break;

	default:
		break;
	}


}

void PopEnemy::Draw()
{

	switch (enemyType_)
	{
	case NOMAL:
		nEnemy_->Draw();
		break;

	case BULLET:

		break;

	default:
		break;
	}

}



