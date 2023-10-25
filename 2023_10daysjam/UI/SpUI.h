#pragma once
#pragma once
#include <Vector2.h>
#include <ScreenSize.h>
#include <Novice.h>
#include "ImGuiManager.h"
#include "Function/UtilityStruct.h"

/// <summary>
/// HP表示のクラス
/// </summary>
class SpUI
{
public:

	//~SpUI();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(float decreasedSp);

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw();

private:

	//左端
	HpState Lpos_ = { 0,60 };
	//右端
	HpState Rpos_ = { 0,0};
	//画像
	int image_ = 0;
	//写したいサイズ
	const int sizeX_ = 500;
	const int sizeY_ = 32;

	//移動した合計
	int moveX_ = 0;
	//移動する量(HPが1減るたびに動く量)
	int moveSpeedX_ = 1;

};


