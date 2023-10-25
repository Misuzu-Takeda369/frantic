#pragma once
#include <cstdint>

/// <summary>
/// 色用の構造体
/// </summary>
struct UnitColor	
{	int R; int G; int B; int A;
	unsigned int color;
	
};

enum STATE {
	IDOL,   //0_待機
	MOVE,   //1_移動
	JUMP,   //2_ジャンプ
	DEAD,   //3_死亡
	ATTACK, //4_攻撃
	SKILL,  //5_魔法など
	SPECIAL,//6_特殊攻撃?
};




