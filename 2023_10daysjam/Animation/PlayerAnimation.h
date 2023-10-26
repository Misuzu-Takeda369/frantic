#pragma once
#include "Animation.h"
#include "Animation/PlayerIdolAnim.h"
#include "Animation/PlayerRunAnim.h"
#include "Function/UtilityStruct.h"
class PlayerAnimation 
{
public:
    ~PlayerAnimation();
    PlayerAnimation();
    void Initialize();
    void Update(Vector2 pos, STATE main, SABSTATE sab);
    void SetDirection(bool right);
    void Draw();
private:
    bool _isDirectionRight;
    PlayerIdolAnim* _idol = nullptr;
    PlayerRunAnim* _run = nullptr;
    Animation* _now = nullptr; //現在使うアニメーション
};

