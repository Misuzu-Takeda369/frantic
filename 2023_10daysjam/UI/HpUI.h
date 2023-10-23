#pragma once
#include <Vector2.h>
#include <Novice.h>
#include "ImGuiManager.h"

/// <summary>
/// HP表示のクラス
/// </summary>
class HpUI
{
public:


private:

	//左端
	Vector2 Lpos_ = {0.0f,0.0f};
	//右端
	Vector2 Rpos_ = { 0.0f,0.0f };
	//画像
	int image_= 0;
	//画像サイズ
	const int sizeX = 440;
	const int sizeY = 64;
};

