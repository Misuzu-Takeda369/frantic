﻿#include "PopItem.h"

PopItem::~PopItem()
{
	delete spRecoverItem_;
}

void PopItem::Initialize()
{

	run_ = 1;
	popItem_ = SpRecover;

#pragma region ポップした時の判別
	//run_ = RandomRange(1, 1);
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
	spRecoverItem_->Update();

	switch (popItem_)
	{
	case SpRecover:

		spRecoverItem_->Update();

		break;

	case HpRecover:

		break;

	default:
		break;
	}
}

void PopItem::Draw()
{
	switch (popItem_)
	{
	case SpRecover:
		spRecoverItem_->Draw();
		break;

	case HpRecover:

		break;

	default:
		break;
	}
}