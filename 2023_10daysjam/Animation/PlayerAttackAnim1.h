#pragma once
#include "Animation.h"
class PlayerAttackAnim1 :
    public Animation
{
public:
	void Initialize()override;
	void Update(Vector2 pos)override;
	void Draw()override;
	void SetDirection(bool right)override;

private:
	unsigned static const int _maxFrame = 6;
	TexturePos _texPos;
	unsigned int _texture[_maxFrame];
	Vector2 _pos;
	int _frame = 0;
	bool _right;
};

