#pragma once
#include "NEnemy.h"
#include "Object/Object.h"

class NEnemy: public Object
{
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
	void Draw() override;
};

