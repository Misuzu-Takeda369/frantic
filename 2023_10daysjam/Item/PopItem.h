#pragma once
#include <Novice.h>
#include "ImGuiManager.h"
#include "Function/Function.h"
#include "SpRecoverItem.h"


/// <summary>
/// アイテムポップを管理する関数
/// </summary>
class PopItem
{
public:


	enum ItemStyle {
		SpRecover,HpRecover
	};


	~PopItem();
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

	ItemBase* nowItem_ = nullptr;

	//Sp回復フラグ
	SpRecoverItem* spRecoverItem_ = nullptr;

};

