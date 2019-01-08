// timerParameter.h
#pragma once
#include "arduino.h"
#include "common.h"


class TimerParameter {
public:
	TimerParameter(ULONG time, void(*function)(), bool one_loop);
	bool timerCompareCheck();
	void functionBegin();
private:
	void(*_function)();		
	bool _oneLoop;
	ULONG _timeLimit;
	ULONG _timeStart;
	ULONG _timeRest;  
	ULONG _timeSpan; 
	bool _enabled;		
	void resetTimer();
};
