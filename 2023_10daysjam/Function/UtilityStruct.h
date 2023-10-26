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

//HpとSPゲージ用のっぽい何か(まとめたかった)
//Noviceの画像処理がint統一なのでintでまとめる
struct IntState {
	int x_;
	int y_;
};

//アニメーション分け&移動制御用 だと思う
enum SABSTATE {
	_NONE,   //0_特になし
	_ATTACK, //1_攻撃中
	_SPELL,  //2_詠唱中
};

