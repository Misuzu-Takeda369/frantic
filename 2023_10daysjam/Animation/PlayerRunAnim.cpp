#include "PlayerRunAnim.h"
#include "Function/Function.h"

void PlayerRunAnim::Initialize()
{
	_texture[0] = Novice::LoadTexture("./AnimResources/w1.png");
	_texture[1] = Novice::LoadTexture("./AnimResources/w4.png");
	_texture[2] = Novice::LoadTexture("./AnimResources/w2.png");
	_texture[3] = Novice::LoadTexture("./AnimResources/w3.png");
	_spriteSize = { 512.0f,512.0f };
	_spriteRadius = { _spriteSize.x * 0.25f,_spriteSize.y  * 0.25f };
}

void PlayerRunAnim::Draw()
{
	Novice::DrawSprite((int)_pos.x + _directionPos, (int)_pos.y, _texture[_frame], 0.25f * _direction, 0.25f, 0, WHITE);
}

void PlayerRunAnim::SetDirection(bool right)
{
	_right = right;
}

void PlayerRunAnim::PosReset()
{
	_frame = 0;
}

void PlayerRunAnim::Update(Vector2 pos)
{
	_pos = pos;
	_timer++;
	if (_right) {
		_direction = 1.0f;
		_directionPos = 0;
	}
	else {
		_direction = -1.0f;
		_directionPos = (int)_spriteRadius.x;
	}
	if (_timer >= 7) {
		_frame = AnimationNum(_frame, 4);
		_timer = 0;
	}

}