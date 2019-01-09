// timerParameter.h
#pragma once
#include "arduino.h"
#include "common.h"

class TimerParameter {
public:
    TimerParameter();
    void timerInit(unsigned long time, void(*function)(), bool one_loop);
    bool timerCompareCheck();
    void functionBegin();

private:
    void(*_function)();
    bool _oneLoop;
    unsigned long _timeLimit;
    unsigned long _timeStart;
    unsigned long _timeRest;
    unsigned long _timeSpan;
    bool _enabled;
    void resetTimer();
};
