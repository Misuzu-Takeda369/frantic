#include "EnemyBase.h"

void EnemyBase::Initialize(Vector2& pos, Vector2& speed, float& radius)
{
	//体力や攻撃力が個体によって違う可能性があるため
	pos; speed; radius;
}

void EnemyBase::Update()
{

}

void EnemyBase::Draw()
{
}

void EnemyBase::Move()
{
	charaBase_.pos_.x -= charaBase_.speed_.x;
}
