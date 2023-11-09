﻿#pragma once
#include <Novice.h>
#include "Function/UtilityStruct.h"
/// <summary>
/// タイトルシーンのクラス
/// </summary>

class TitleScene
{
public:

	enum TitleSMode {
		None, Expriense, Option
		//何もなし,操作説明,オプション？
	};
	/// <summary>
	/// コンストクラタ
	/// </summary>
	TitleScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~TitleScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw();

	/// <summary>
	/// マウスでのシーン変換
	/// </summary>
	void MouseBottonChack();

	/// <summary>
	/// シーン変更管理のゲッター
	/// </summary>
	/// <returns></returns>
	bool GetFlagChange() { return flagChange_; };

	/// <summary>
	/// シーン変更管理のセッター
	/// </summary>
	/// <returns></returns>
	bool SetFlagChange(bool flagChange) { return this->flagChange_ = flagChange; };

private:

	//シーン変更できるかどうか
	bool flagChange_ = false;

	/// <summary>
	/// 現在のタイトル画面のモード
	/// </summary>
	int titleSModeNow_ = None;

	//受け取りのせいですぐに変わるのでそれを防ぐためのラグ(後で消える)
	int changeTimingFrame_ = 40;

	///リソース関連
	int titleImage_ = 0;
	int startImage_ = 0;

	IntState startPos_;
	const int startSizeX_ = 384;
	const int startSizeY_ = 128;

	//マウスの位置(Yも無いと関数動かん)
	IntState mousePos_ = { 0,0 };
	UnitColor startColor_ = { 255,255,255,255,0xFFFFFFFF };

};