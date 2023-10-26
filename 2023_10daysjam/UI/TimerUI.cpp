#include "TimerUI.h"

void TimerUI::Initialize()
{
	timerUIPos_ = {20,600};
	timer_ = 3600;
	timerDisplay_ = timer_/60;
}

void TimerUI::Update()
{
	timer_--;
	timerDisplay_ = timer_ / 60;

	if (timer_<= 0) {
		timer_ = 3600;
	}
}

void TimerUI::Draw()
{

#ifdef _DEBUG
	Novice::ScreenPrintf(timerUIPos_.x_, timerUIPos_.y_,"Timer: %d", timerDisplay_);
#endif // _DEBUG

}
