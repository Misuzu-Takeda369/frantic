#pragma once
#include <Novice.h>
#include "ImGuiManager.h"
#include "Function/Function.h"

class ItemBase
{
public:

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 前景描画
	/// </summary>
	virtual void Draw();

private:

	//位置
	Vector2 pos_;
	//画像サイズ
	int sizeX_; int sizeY_;
	int image_;
};

