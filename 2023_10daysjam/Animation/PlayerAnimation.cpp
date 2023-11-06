﻿#include "PlayerAnimation.h"
#include "Function/Function.h"

PlayerAnimation::~PlayerAnimation()
{
	delete _idol;
	delete _run;
	delete _attack1;
	delete _attack2;
	for (LunaMentalEffect* effect : _lunaticEffect) {
		delete effect;
	}
	//delete _now;
}

PlayerAnimation::PlayerAnimation()
{
}

void PlayerAnimation::Initialize()
{
	_maindState = Normal;
	_idol = new PlayerIdolAnim;
	_idol->Initialize();
	_run = new PlayerRunAnim;
	_run->Initialize();
	_attack1 = new PlayerAttackAnim1;
	_attack1->Initialize();
	_attack2 = new PlayerAttack2Anim;
	_attack2->Initialize();

	_now = new Animation;
	_now->Initialize();
	_isDirectionRight = 1;
	_lunaEffectTimer = 0;
}

void PlayerAnimation::Update(Vector2 pos, STATE main, SABSTATE sab,  MaindState maindState, PlayerDirection mDclection, PlayerDirection aDclection)
{
	//感情の受け取りを関数に変更
	SetMaindState(maindState);

	switch (main)
	{
	case IDOL:

		//攻撃と移動で向きの変更条件が別なため
		if (mDclection == RIGHT) {
			_isDirectionRight = true;
		}
		else {
			_isDirectionRight = false;
		}

		_idol->Update(pos);
		_idol->SetDirection(_isDirectionRight);
		_now = (Animation*)_idol;
		break;
	case MOVE:

		if (mDclection == RIGHT) {
			_isDirectionRight = true;
		}
		else {
			_isDirectionRight = false;
		}

		_run->Update(pos);
		_run->SetDirection(_isDirectionRight);
		_now = (Animation*)_run;
		break;
	case JUMP:

		if (mDclection == RIGHT) {
			_isDirectionRight = true;
		}
		else {
			_isDirectionRight = false;
		}

		_run->Update(pos);
		_run->SetDirection(_isDirectionRight);
		_now = (Animation*)_run;
		break;
	case DEAD:
		break;
	case ATTACK:

		if (aDclection == RIGHT) {
			_isDirectionRight = true;
		}
		else {
			_isDirectionRight = false;
		}

		_attack1->Update(pos);
		_attack1->SetDirection(_isDirectionRight);
		_now = (Animation*)_attack1;
		_attack1->SetActive(true);
		break;
	case SKILL:

		if (aDclection == RIGHT) {
			_isDirectionRight = true;
		}
		else {
			_isDirectionRight = false;
		}

		_attack2->Update(pos);
		_attack2->SetDirection(_isDirectionRight);
		_now = (Animation*)_attack2;
		break;
	case SPECIAL:
		break;
	default:
		break;
	}
	sab;

	if (main != ATTACK) {
		_attack1->SetActive(false);
	}

	if (_maindState == Lunatic) {
		_lunaEffectTimer++;
		if (_lunaEffectTimer >= 3) {
			AddLunaEffect(pos);
			_lunaEffectTimer = 0;
		}
		_lunaticEffect.remove_if([](LunaMentalEffect* effect) {
			if (!effect->GetIsArrive()) {
				delete effect;
				return true;
			}
			return false;
			});
		for (LunaMentalEffect* effect : _lunaticEffect) {
			effect->Update(pos);
		}
	}
	else {
		_lunaEffectTimer = 0;
		if (_lunaticEffect.size() > 1) {
			for (int i = 0; i < _lunaticEffect.size(); i++) {
				_lunaticEffect.pop_back();
			}
		}
	}
}

void PlayerAnimation::SetDirection(bool right)
{
	_isDirectionRight = right;
}

void PlayerAnimation::SetMaindState(const MaindState& state)
{
	_maindState = state;
	_attack1->SetIsLunatic(_maindState);
	_idol->SetIsLunatic(_maindState);
	_attack2->SetIsLunatic(_maindState);
	_run->SetIsLunatic(_maindState);
}

void PlayerAnimation::Draw()
{
	_now->Draw(_defaultColor);

	if (_maindState==Lunatic) {
		for (LunaMentalEffect* effect : _lunaticEffect) {
			effect->Draw();
		}
	}
}

void PlayerAnimation::AddLunaEffect(const Vector2& pos)
{
	LunaMentalEffect* obj = new LunaMentalEffect();
	obj->Initialize(pos);
	_lunaticEffect.push_back(obj);
}

