#pragma once
#include "EnemyBullet.h"
#include "Vector2.h"
#define ENEMY_MAX 10

//敵クラス
class Enemy
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
};

