#pragma once
#include <Vector2.h>

struct CharaBase {
	Vector2 pos_;
	Vector2 speed_;
	float radius_;
	float attack_;
	unsigned int color;
	int image_;
};