#include "PlayerAnimation.h"

PlayerAnimation::~PlayerAnimation()
{
	delete _idol;
	delete _run;
	//delete _now;
}

PlayerAnimation::PlayerAnimation()
{
}

void PlayerAnimation::Initialize()
{
	_idol = new PlayerIdolAnim;
	_idol->Initialize();
	_run = new PlayerRunAnim;
	_run->Initialize();
	_now = new Animation;
	_now->Initialize();
	_isDirectionRight = 1;
}

void PlayerAnimation::Update(Vector2 pos, STATE main, SABSTATE sab)
{
	switch (main)
	{
	case IDOL:
		_idol->Update(pos);
		_idol->SetDirection(_isDirectionRight);
		_now = (Animation*)_idol;
		break;
	case MOVE:
		_run->Update(pos);
		_run->SetDirection(_isDirectionRight);
		_now = (Animation*)_run;
		break;
	case JUMP:
		break;
	case DEAD:
		break;
	case ATTACK:
		break;
	case SKILL:
		break;
	case SPECIAL:
		break;
	default:
		break;
	}
	sab;
}

void PlayerAnimation::SetDirection(bool right)
{
	_isDirectionRight = right;
}

void PlayerAnimation::Draw()
{
	_now->Draw();
}
