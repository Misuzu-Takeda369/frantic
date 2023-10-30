#include "PopItem.h"

void PopItem::Initialize()
{

	run_ = 0;
	popItem_ = SpRecover;

	nowItem_ = new ItemBase();
	nowItem_->Initialize();
#pragma region ポップした時の判別
	run_ = RandomRange(1, 2);
	if (run_ == 1) {
		popItem_ = SpRecover;
	}
	else if (run_ == 2) {
		popItem_ = HpRecover;
	}

	switch (popItem_)
	{
	case SpRecover:
			spRecoverItem_ = new SpRecoverItem();
			spRecoverItem_->Initialize();
			nowItem_ = (ItemBase*)spRecoverItem_;
			
		break;

	case HpRecover:

		break;

	default:
		break;
	}
#pragma endregion

}

void PopItem::Update()
{
	nowItem_->Update();

	if (nowItem_->IsDead()) {
		delete nowItem_;
	}
}

void PopItem::Draw()
{
	nowItem_->Draw();
}
