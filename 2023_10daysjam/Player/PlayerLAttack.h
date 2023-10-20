#pragma once
#include <Vector2.h>
#include <Novice.h>
#include "ImGuiManager.h"
#include "CharaBase.h"

class PlayerLAttack
{
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


private:

	CharaBase charaBase_;

	///プレイヤーから引っ張ってくる引数
	//現在の攻撃type
	bool playerAttackTypeNow_;
	//現在の狂気度
	int maindStateNow_;
	//プレイヤーの向き
	int playerDirection_;

};

