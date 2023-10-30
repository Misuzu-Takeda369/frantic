﻿#pragma once
#include <Vector2.h>
#include <Novice.h>
#include "ImGuiManager.h"
#include "CharaBase.h"

class Object
{

public:
	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	virtual void Update(char* keys, char* preKeys);

	/// <summary>
	/// 前景描画
	/// </summary>
	virtual void Draw();

	virtual void OnCollision();
	/// <summary>
	/// 現在のHP
	/// </summary>
	/// <returns></returns>
	virtual float GetPlayerHp() { return hp_; };
	/// <summary>
	/// 現在のSP
	/// </summary>
	/// <returns></returns>
	virtual float GetPlayerSp() { return sp_; };

	/// <summary>
	/// 当たり判定に使う用のゲッターX
	/// </summary>
	/// <returns></returns>
	virtual float GetPosX() { return charaBase_.pos_.x; };
	/// <summary>
	/// 当たり判定に使う用のゲッターY
	/// </summary>
	/// <returns></returns>
	virtual float GetPosY() { return charaBase_.pos_.y; };
	/// <summary>
	/// 当たり判定に使う用のゲッター半径
	/// </summary>
	/// <returns></returns>
	virtual float GetRadish() { return charaBase_.radius_; };

protected:

	//基準となる情報(ここからアニメーション用に引っ張る)
	CharaBase charaBase_;

	float hp_;
	float sp_;

	//現在の狂気度
	MaindState maindStateNow_ = Normal;
	//狂気カラー(デバック用)
	unsigned int maindColor_ = WHITE;
	//精神状態が変わる値の変数
	float spChangingPoint_ = 250.0f;
};

