#pragma once
#include "Object/Object.h"

class EnemyBase : public Object
{

public:
	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize(Vector2 pos, Vector2 speed, float radius);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	virtual void Update() override;

	/// <summary>
	/// 前景描画
	/// </summary>
	virtual void Draw()override;

	/// <summary>
	/// 敵の移動処理
	/// </summary>
	virtual void Move();

	/// <summary>
	/// 自然に消えるパターン
	/// </summary>
	virtual void NaturalDeath();

	//敵の攻撃力のゲッター
	virtual float GetEnemyAttackPoint() { return attackpoint_; };

	//敵が死んでいるか
	virtual bool GetIsDead() { return isDead_; };

protected:

	//敵の体力
	float hp_;

	//プレイヤーに影響する攻撃力
	float attackpoint_;

	//敵が死んでいるか
	bool isDead_;

	//敵が移動した量
	Vector2 moveEnemy_;

};

