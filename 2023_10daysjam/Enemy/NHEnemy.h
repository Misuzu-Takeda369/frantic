﻿#pragma once
#include "EnemyBase.h"
#include "Animation/Enemy1Anim.h"

class NHEnemy :public EnemyBase
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Vector2 pos, Vector2 speed, float radius) override;

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update()override;

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw() override;
	
private:

	//体力の最大値
	const float maxHp_ = 10.0f;

	//コイツの火力
	const float nomalPoint_ = 10.0f;

	//アニメーション
	Enemy1Anim* animation_ = nullptr;
};

