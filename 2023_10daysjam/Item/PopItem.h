#pragma once
#include <Novice.h>
#include "ImGuiManager.h"
#include "Function/Function.h"

class PopItem
{
public:
	enum ItemStyle {
		SpRecover,HpRecover
	};
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw();

private:

	int run_;
	ItemStyle popItem_;

};

