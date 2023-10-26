#pragma once
#include "Animation/Animation.h"
class PlayerIdolAnim :public Animation
{
public:
	void Initialize()override;
	void Update(Vector2 pos)override;
	void Draw()override;
	void SetDirection(bool right)override;

private:
	TexturePos _texPos;
	unsigned int _texture[3];
	Vector2 _pos;
	bool _right;

	int _frame = 0;
};

