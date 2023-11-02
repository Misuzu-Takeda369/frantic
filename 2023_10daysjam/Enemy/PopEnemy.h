#pragma once
#include "EnemyBullet.h"
#include "Object/Object.h"
#include "NEnemy.h"
#include "Function/Function.h"
#include "EnemyBase.h"
#define ENEMY_MAX 10

//敵クラス(総括クラスポップ用に変更)
class PopEnemy :public EnemyBase
{
public:

	enum EnemyType
	{
		NOMAL,BULLET
	};

	~PopEnemy();

	//後から場所だけ敵から受け取る
	void Initialize();

	void Update() override;
	void Draw() override;

private:

	//通常の敵
	NEnemy* nEnemy_ = nullptr;

	//現在出ている敵の数(ENEMY_MAXになると減るまで敵がでなくなる)
	int countEnemy_ = 0;

	//乱数用の数
	int rumNum_ = 0;
	//敵の種類用
	EnemyType enemyType_ = NOMAL;

};

