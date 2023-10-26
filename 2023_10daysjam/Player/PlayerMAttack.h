#pragma once
#include <Vector2.h>
#include <Novice.h>
#include "ImGuiManager.h"
#include "CharaBase.h"


//近距離用の
class PlayerMAttack
{
public:
	
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="playerAttackTypeNow">攻撃のtype</param>
	/// <param name="maindStateNow">現在狂気か否か</param>
	/// <param name="playerDirection">向き</param>
	void Initialize(PlayerAttackType& playerAttackTypeNow, MaindState& maindStateNow, PlayerDirection& playerDirection);
	//必要な引数
	//狂気か否か、攻撃type、プレイヤーの向き、

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(Vector2& playerPos, PlayerDirection& playerDirection);
	//プレイヤーの現在地、

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 攻撃力を決める関数
	/// </summary>
	void DeterminingAttackPower(float hp, float maxHp);

private:

	CharaBase charaBase_;

	///プレイヤーから引っ張ってくる引数
	//現在の攻撃type
	PlayerAttackType playerAttackTypeNow_;
	//現在の狂気度
	MaindState maindStateNow_;
	//プレイヤーの向き
	PlayerDirection playerDirection_;

	//本体と近距離当たり判定の中心までどれぐらい離れているか
	const Vector2 ptoA_ = { 64.0f,0.0f };

	//最終的に判断する攻撃力
	float attackPoint_ = 0.0f;
	//計算時の倍率
	const float attackMultiples_ = 2.0f;
	//攻撃力(通常時　変動なし？)
	const float nomalAttackPoint_ = 2.0f;
	//攻撃力(magic時　変動あり)
	float magicAttackPoint_ = 10.0f;

};

