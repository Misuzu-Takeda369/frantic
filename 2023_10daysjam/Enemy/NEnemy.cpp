#include "NEnemy.h"

void NEnemy::Initialize()
{
}

void NEnemy::Update()
{
	//敵の移動
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemyPos[i].x -= enemySpeed;

		//敵の攻撃
		if (E_Bullet->enemy_isShot == false) {
			E_Bullet->enemy_isShot = true;
			E_Bullet->bulletPos.x = enemyPos[i].x - enemyRadius;
			E_Bullet->bulletPos.y = enemyPos[i].y;
		}
	}

	if (E_Bullet->enemy_isShot == true) {
		E_Bullet->bulletPos.x -= E_Bullet->bulletSpeed;
	}

	if (E_Bullet->bulletPos.x <= E_Bullet->bulletRadius) {
		E_Bullet->enemy_isShot = false;
	}

	if (enemyHp == 0) {
		E_Bullet->enemy_isShot = false;
	}


}

void NEnemy::Draw()
{
}
