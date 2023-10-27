#pragma once
#include <Novice.h>
#include "ImGuiManager.h"
#include "Function/Function.h"
#include "Item/ItemBase.h"


class SpRecoverItem :public ItemBase
{

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize()override;

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update()override;

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw()override;


	float GetRecoverSp() { return recoverSp_; }

	float GetDownLineLunatic() { return downLineLunatic_; }


	
private:

	//実際に回復する量
	float recoverSp_;
	//回復する量(定数)
	const float recoveryAmount_ = 5.0f;
	//ラインが下がる量
	float downLineLunatic_;
	//狂気ラインダウン(定数)
	const float downLineLunaticAmount_ = 2.0f;
	
};

