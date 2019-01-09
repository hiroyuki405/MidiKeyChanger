// timerState.h
#pragma once
#include "arduino.h"
#include "common.h"
#include "timerParameter.h"
#include "hardInterface.h"

#define TIMER_BUF 10

class TimerState {
public:
    TimerState();
    void init();
    void timerUpdate();
    bool timerSet(ULONG time, void(*function)(), bool one_loop);
private:
    TimerParameter _timerParameter[TIMER_BUF];
    int _timerSize;
};

