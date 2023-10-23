﻿#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <cstdint>
#include "Vector2.h"

/// <summary>
/// 角度の変換
/// </summary>
/// <param name="a">degree(0～360°)</param>
/// <returns></returns>
float DegreeToRadian(float a);

/// <summary>
/// 角度の変換
/// </summary>
/// <param name="a">radian</param>
/// <returns></returns>
float RadianToDegree(float a);

/// <summary>
/// 色の設定(返り値) 10進数を入力
/// </summary>
/// /// <param name="R">Rの値</param>
/// /// <param name="G">Gの値</param>
/// /// <param name="B">Bの値</param>
/// /// <param name="A">Aの値</param>
/// <returns></returns>
int GetColorValue(int R, int G, int B, int A);

/// <summary>
/// 整数で範囲をランダムに出す(もしかしたらバグあるかも)
/// </summary>
/// <param name="min">最小値</param>
/// <param name="max">最大値</param>
/// <returns></returns>
int RandomRange(int min, int max);

/// <summary>
/// 円の衝突判定
/// </summary>
/// <param name="aX">円１　x</param>
/// <param name="aY">円１　y</param>
/// <param name="aRadius">円１　半径</param>
/// <param name="bX">円２　x</param>
/// <param name="bY">円２　y</param>
/// <param name="bRadius">円２　半径</param>
/// <returns></returns>
bool CircleCollision(float aX, float aY, float aRadius, float bX, float bY, float bRadius);


/// <summary>
/// アニメーション変化関数
/// </summary>
/// <param name="animationNum">何番目かの変数</param>
/// /// <param name="maxFrame">アニメーションの合計フレーム数</param>
/// <returns></returns>
uint32_t AnimationNum(uint32_t animationNum,uint32_t maxFrame);


/// <summary>
/// 正規化
/// </summary>
/// <param name="v">正規化したい値</param>
/// <returns></returns>
//Vector2 Normalize(const Vector2& v);

void TranslateWave(float& pos, const float& theta, float range1, float range2);

/// <summary>
/// 円周移動 
/// </summary> 
/// <param name="v"></param>
/// <param name="theta"></param>
void CircumferentialMovement(Vector2& v, const float& theta);