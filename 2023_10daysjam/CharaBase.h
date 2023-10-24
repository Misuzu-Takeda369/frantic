﻿#pragma once
#include <Vector2.h>
#include "Function/UtilityStruct.h"

struct CharaBase {
	Vector2 pos_;
	Vector2 speed_;
	float radius_;
	float attack_;
	unsigned int color_;
	//色の構造体適応するパターン
	//UnitColor Color_;
	int image_;
};

///プレイヤーの精神状態
enum MaindState {
	//0.通常,1.狂気
	Normal, Lunatic
};

///プレイヤーの攻撃モード
enum PlayerAttackType {
	Plane, Magic
};

///プレイヤーの攻撃向き
enum PlayerDirection {
	//0:左,1:右
	Left, RIGHT
};