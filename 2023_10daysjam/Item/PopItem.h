#pragma once
#include <Novice.h>
#include "ImGuiManager.h"
#include "Function/Function.h"
#include "SpRecoverItem.h"
#include "ItemBase.h"


/// <summary>
/// アイテムポップを管理する関数
/// </summary>
class PopItem : public ItemBase 
{

public:


	enum ItemStyle {
		SpRecover,HpRecover
	};


	~PopItem();
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update()override;

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw()override;

	SpRecoverItem* GetSpRecoverItem() { return spRecoverItem_; };

private:

	int run_;
	ItemStyle popItem_;

	//Sp回復フラグ
	SpRecoverItem* spRecoverItem_ = nullptr;

};

