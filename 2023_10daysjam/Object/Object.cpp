#include "Object.h"

void Object::MindTypeChange()
{

	if (sp_ <= spChangingPoint_) {
		maindStateNow_ = Lunatic;
		maindColor_ = RED;
	}
	else {
		maindStateNow_ = Normal;
		maindColor_ = WHITE;
	}

}
