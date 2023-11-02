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
	charaBase_.speed_ = {0.8f,0.3f};
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
		hp_ = nEnemy_->GetHp();

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

	CoolCheak();

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


#ifdef _DEBUG
#pragma region ImGui関連

	ImGui::Begin("EnemyHp");
	ImGui::Text("EnemyHp %f\n", hp_);
	
	ImGui::End();
#pragma endregion
#endif // DEBUG
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

void PopEnemy::OnCollision(float& damege)
{
	//damege;
	//hp_ -= 10.0f;
	
	if (!hit_) {
		hp_ -= damege;
		hit_ = true;
	}

	if (hp_ <= 0.0f) {
		isDead_ = true;
	}

}

void PopEnemy::CoolCheak()
{
	if (hit_) {
		hitCoolTime_++;

		if (hitCoolTime_ >= MaxHitCoolTime_) {
			hit_ = false;
			hitCoolTime_ = 0;
		}
	}
}



