#pragma once
#include <Vector2.h>
#include <Adapter/Novice.h>
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
	void Initialize(bool& playerAttackTypeNow, int& maindStateow,int& playerDirection);
	//必要な引数
	//狂気か否か、攻撃type、プレイヤーの向き、

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(Vector2& playerPos,int& playerDirection);
	//プレイヤーの現在地、

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw();


private:

	CharaBase charaBase_;

	///プレイヤーから引っ張ってくる引数
	//現在の攻撃type
	bool playerAttackTypeNow_;
	//現在の狂気度
	int maindStateNow_;
	//プレイヤーの向き
	int playerDirection_;

	//本体と近距離当たり判定の中心までどれぐらい離れているか
	const Vector2 ptoA_ = { 64.0f,0.0f };

};

