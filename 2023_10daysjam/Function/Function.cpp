﻿#include "Function.h"
float DegreeToRadian(float a) {
	float radian;
	radian = a * (float(M_PI) / 180.0f);
	return radian;
}

float RadianToDegree(float a)
{
	float degree;
	degree = a * (180.0f / float(M_PI));
	return degree;
}


int GetColorValue(int R, int G, int B, int A)
{
	unsigned int result;
	int r = R / 16; int g = G / 16; int b = B / 16; int a = A / 16;
	int r2 = R % 16; int g2 = G % 16; int b2 = B % 16; int a2 = A % 16;
	int r3 = (r * 0x10) + (r2 * 0x1);
	int g3 = (g * 0x10) + (g2 * 0x1);
	int b3 = (b * 0x10) + (b2 * 0x1);
	int a3 = (a * 0x10) + (a2 * 0x1);
	R = 0x1000000 * r3;
	G = 0x10000 * g3;
	B = 0x100 * b3;
	A = 0x1 * a3;
	result = R + G + B + A;
	return result;
}

int RandomRange(int min, int max)
{
	unsigned int range = 0;
	srand(int(time(nullptr) * rand()));
	srand(rand());
	if (min < 0) {
		range = max + (-min) + 1;

	}
	if (min > 0) {
		range = max - min + 1;
	}
	if (min == 0) {
		range = max + 1;
	}
	int num = rand() % range + min;
	return num;
}

bool CircleCollision(float aX, float aY, float aRadius, float bX, float bY, float bRadius) {
	float pos = (aX - bX) * (aX - bX) + (aY - bY) * (aY - bY);
	float radius = (aRadius + bRadius) * (aRadius + bRadius);
	if (pos < radius) {
		return true;
	}
	else {
		return false;
	}
}

uint32_t AnimationNum(uint32_t animationNum, uint32_t maxFrame)
{

	animationNum++;
	if (animationNum >= maxFrame) {
		animationNum = 0;
	}

	return animationNum;
}


/*
Vector2 Normalize(const Vector2& v) {
	Vector2 result = { 0.0f,0.0f };

	float le = sqrt((v.x * v.x) + (v.y * v.y));

	if (le != 0.0f) {
		result.x = v.x / le;
		result.y = v.y / le;
	}

	return result;

}
*/

void TranslateWave(float& pos, const float& theta, float range1, float range2)
{
	float num = pos + (range1 * cosf(theta) + range2 * sinf(theta));
	pos = num;
}

void CircumferentialMovement(Vector2& v, const float& theta)
{
	const Vector2 v2 = v;
	v.x = v2.x * cosf(theta) - v2.y * sinf(theta);
	v.y = v2.y * cosf(theta) + v2.x * sinf(theta);
}
