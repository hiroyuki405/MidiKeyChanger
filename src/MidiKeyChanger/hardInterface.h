// hardInterface.h
#pragma once
#include <inttypes.h>
#include "common.h"
#include <MIDI.h>
#include <arduino.h>
#include "timerState.h"
#define PIN_PREV 2
#define PIN_NEXT 4
#define PIN_LED 10
#define CHATTERING_COUNT 20
#define CHATTERING_SPAN 1
#define CHATTERING_FLAG TRUE
 
extern TimerState g_pTimerState;
	
enum PIN_MONITOR{
	LED_FLASH,
	MONITOR_SIZE,
};

enum PINSTATE{
	ON=LOW,
	OFF=HIGH,
};

enum PINMON_STATE{
	NONE,
	UNSET,
	SET,
};

// typedef struct PINMON{
// 	int onCount;
// 	int offCount;
// 	int pinNo;
// 	enum PINSTATE state;
// 	enum PINMON_STATE monState;
	
// }tagPINMON, *tagLPPINMON;


class PinMonitor{
public:
	PinMonitor(int pinNo);
	int _onCount;
	int _offCount;
	int _pinNo;
	enum PINSTATE _state;
	enum PINMON_STATE _monState;
};

class HardInterFace {
public:
	static bool getMidi(Common::LPMIDIDATAS pData);
	static void sendMidi(const Common::LPMIDIDATAS data);
	static void initMidi(int ch);
	static void initPinMode();
	static void timerFuncPinMonitor();
	static void ledFlash(PINSTATE light);

private :
	static void inputPin();
	static void outputPin();
	static PinMonitor *_pinMon[];
	// static bool pinInverseCheck(tagLPPINMON pindata);
	static void pinChange(PinMonitor *pin);
};
