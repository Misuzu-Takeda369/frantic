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
	/*
	//初期化
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemyPos[i].x = -100.f;
		enemyPos[i].y = -100.f;
	}

	enemyPos[0].x = 1100.f;
	enemyPos[0].y = 550.f;
	enemyPos[1].x = 1400.f;
	enemyPos[1].y = 550.f;

	enemyHp = 3;
	enemyRadius = 50;
	enemySpeed = 0.3f;

	E_Bullet = new EnemyBullet;


	*/
	charaBase_.pos_ = { 1400.f,550.0f};
	charaBase_.speed_ = {0.3f,0.3f};
	charaBase_.radius_ = 50;
	

	popFrame_ = 0;
	countEnemy_ = 0;
	rumNum_ = 0;
	enemyType_ = NOMAL;

#pragma region ポップした時の判別
	rumNum_ = RandomRange(1, 1);
	if (rumNum_ == 1) {
		enemyType_ = NOMAL;
	}
	else if (rumNum_ == 2) {
		enemyType_ = BULLET;
	}

	switch (rumNum_)
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
	switch (rumNum_)
	{
	case NOMAL:
		//nEnemy_->Update();
		break;

	case BULLET:

		break;

	default:
		break;
	}

/*
#ifdef _DEBUG

	ImGui::Begin("Enemy");
	ImGui::Text("enemyHP: %d\n", enemyHp);
	ImGui::Text("enemyPos 1: %f, %f\n", enemyPos[0].x, enemyPos[0].y);
	ImGui::Text("enemyPos 2: %f, %f\n", enemyPos[1].x, enemyPos[1].y);
	ImGui::End();

#endif // DEBUG
*/
}

void PopEnemy::Draw()
{
	/*
	//敵の描画
	for (int i = 0; i < ENEMY_MAX; i++) {
		Novice::DrawEllipse((int)enemyPos[i].x, (int)enemyPos[i].y, enemyRadius, enemyRadius, 0.f, RED, kFillModeSolid);
	}
	if (E_Bullet->enemy_isShot == true) {
		E_Bullet->Draw();
	}
	*/

	switch (rumNum_)
	{
	case NOMAL:
		//nEnemy_->Draw();
		break;

	case BULLET:

		break;

	default:
		break;
	}

}

