#pragma once
#include <Vector2.h>
#include <Novice.h>
#include "ImGuiManager.h"
#include "CharaBase.h"

class PlayerLAttack
{
public:
	/// <summary>
		/// 初期化
		/// </summary>
		/// <param name="playerAttackTypeNow">攻撃のtype</param>
		/// <param name="maindStateNow">現在狂気か否か</param>
		/// <param name="playerDirection">向き</param>
	void Initialize(bool& playerAttackTypeNow, int& maindStateow, int& playerDirection, Vector2& playerPos);
	

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();
	//プレイヤーの現在地、

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw();


	/// <summary>
	/// クラスの外部用弾消えるためのフラグ変数
	/// </summary>
	bool IsDead() const { return isDead_; };

private:

	CharaBase charaBase_;

	///プレイヤーから引っ張ってくる引数
	//現在の攻撃type
	bool playerAttackTypeNow_;
	//現在の狂気度
	int maindStateNow_;
	//プレイヤーの向き
	int playerDirection_;

	//弾の寿命(消えるまでの時間の定数)
	static const int kLifeTime = 120;
	// 弾の寿命(消えるまでの時間の判定用変数)
	int deathTimer_ = kLifeTime;
	//消えるフラグ
	bool isDead_ = false;

	//最終的に判断する攻撃力
	float attackPoint_ = 0;

	//攻撃力(通常時　変動なし？)
	const float nomalAttackPoint = 1.0f;

};

