#include "Enemy.h"
#include "Novice.h"
#include "ImGuiManager.h"

Enemy::Enemy()
{
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

	//nEnemy_ = new NEnemy();
	//nEnemy_->Initialize();
}

Enemy::~Enemy()
{
	delete E_Bullet;
	delete nEnemy_;
}

void Enemy::Update()
{
	
#ifdef _DEBUG

	ImGui::Begin("Enemy");
	ImGui::Text("enemyHP: %d\n", enemyHp);
	ImGui::Text("enemyPos 1: %f, %f\n", enemyPos[0].x, enemyPos[0].y);
	ImGui::Text("enemyPos 2: %f, %f\n", enemyPos[1].x, enemyPos[1].y);
	ImGui::End();

#endif // DEBUG

}

void Enemy::Draw()
{
	//敵の描画
	for (int i = 0; i < ENEMY_MAX; i++) {
		Novice::DrawEllipse((int)enemyPos[i].x, (int)enemyPos[i].y, enemyRadius, enemyRadius, 0.f, RED, kFillModeSolid);
	}
	if (E_Bullet->enemy_isShot == true) {
		E_Bullet->Draw();
	}
}

