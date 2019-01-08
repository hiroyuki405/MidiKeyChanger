// timerState.h
#pragma once
#include "arduino.h"
#include "timerParameter.h"
#include "common.h"
#define TIMER_BUF 10

enum TIMERPARAM {
	MAX
};

///日本語
class TimerState {
public:
	TimerState();
	bool timerSet(ULONG time, void(*function)(), bool one_loop);
	void timerUpdate();
private:
	TimerParameter _timerParameter[TIMERPARAM::MAX];
	int _timerSize;
};
