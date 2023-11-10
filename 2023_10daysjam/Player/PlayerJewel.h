﻿#pragma once
#include "Novice.h"
#include "CharaBase.h"
//攻撃typeを視認的に分かるようにするためのクラス
class PlayerJewel
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Vector2& pos, unsigned int& color);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(Vector2& pos, PlayerAttackType& playerAttackType, PlayerDirection& playerDurection);

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw();

private:

	//写る場所
	CharaBase jewelstate_;

	//画像サイズ
	const IntState imageSize_ = {16,16};


	//プレイヤーからの距離
	const IntState playerDistance_ = {48,32 };
};

