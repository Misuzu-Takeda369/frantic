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
	IDOL,  //0_待機
	MOVE,  //1_移動
	DEAD,  //2_死亡
	ATTACK,//3_攻撃
	SKILL, //4_魔法など
	SPECIAL,//5_特殊攻撃?
};




