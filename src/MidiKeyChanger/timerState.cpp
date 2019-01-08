#include "timerState.h"

TimerState::TimerState()
{
	
}

bool TimerState::timerSet(ULONG time, void(*function)(), bool one_loop)
{
	if (function == NULL) {
		return FALSE;
	}
	return TRUE;
}

void TimerState::timerUpdate()
{
	for (int i = 0; i < TIMERPARAM::MAX; i++) {
		if (_timerParameter[i].timerCompareCheck()) {
			_timerParameter[i].functionBegin();
		}
	}
}
