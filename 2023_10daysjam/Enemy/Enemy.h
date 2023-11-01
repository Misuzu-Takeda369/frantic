#pragma once
#include "EnemyBullet.h"
#include "Object/Object.h"
#include "NEnemy.h"
#define ENEMY_MAX 10

//敵クラス(総括クラスポップ用に変更)
class Enemy :public Object
{
public:

	int enemyHp;
	Vector2 enemyPos[ENEMY_MAX];
	int enemyRadius;
	float enemySpeed;

	EnemyBullet* E_Bullet;

	Enemy();
	~Enemy();

	void Update();
	void Draw();


private:
	//
	NEnemy* nEnemy_ = nullptr;
};

