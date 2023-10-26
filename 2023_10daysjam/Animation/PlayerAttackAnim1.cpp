#include "PlayerAttackAnim1.h"
#include "Function/Function.h"

void PlayerAttackAnim1::Initialize()
{
}

void PlayerAttackAnim1::Update(Vector2 pos)
{
	_pos = pos;
	if (_right) {
		_direction = 1.0f;
		_directionPos = 0;
	}
	else {
		_direction = -1.0f;
		_directionPos = (int)_spriteRadius.x;
	}
	_timer++;
	if (_timer >= 7) {
		_frame = AnimationNum(_frame, _maxFrame);
		_timer = 0;
	}
}

void PlayerAttackAnim1::Draw()
{
}

void PlayerAttackAnim1::SetDirection(bool right)
{
	_right = right;
}
