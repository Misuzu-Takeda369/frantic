#pragma once
#include "Enemy/EnemyBase.h"
class NEnemy :public EnemyBase
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Vector2& pos, Vector2& speed, float& radius) override;

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update()override;

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw() override;

private:

	const float maxHp_ = 3.0f;
};

