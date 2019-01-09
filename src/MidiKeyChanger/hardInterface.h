// hardInterface.h
#pragma once
#include <inttypes.h>
#include <arduino.h>
#include "common.h"
#include "customMIDI.h"
#include "pinMonitor.h"
#include "State.h"
#include "timerState.h"
#include "midiMng.h"

#define PIN_NO_PREV 6
#define PIN_NO_NEXT 7

#define PIN_LED 10
#define PIN_SEG_A 1
#define PIN_SEG_B 2
#define PIN_SEG_C 3
#define PIN_SEG_D 4
#define PIN_SEG_E 5
#define PIN_SEG_F 6
#define PIN_SEG_G 7
#define PIN_SEG_DP 8
#define PIN_SEG_SIZE 9
#define SEGMENT_A   {SEG_A,SEG_B,SEG_F,SEG_G,SEG_E,SEG_C}
#define SEGMENT_B   {SEG_F,SEG_G,SEG_E,SEG_D,SEG_C}
#define SEGMENT_C   {SEG_A,SEG_F,SEG_E,SEG_D}
#define SEGMENT_D   {SEG_B,SEG_C,SEG_D,SEG_E,SEG_G}
#define SEGMENT_E   {SEG_A,SEG_F,SEG_G,SEG_E,SEG_D}
#define SEGMENT_F   {SEG_A,SEG_F,SEG_G,SEG_E}
#define SEGMENT_G  {SEG_A,SEG_F,SEG_E,SEG_D,SEG_C,SEG_G}
#define SEGMENT_ONE  {SEG_B,SEG_C}
#define SEGMENT_TWO  {SEG_A,SEG_B,SEG_G,SEG_E,SEG_D}
#define SEGMENT_THREE {SEG_A,SEG_B,SEG_G,SEG_C,SEG_D}
#define SEGMENT_FOUR {SEG_F,SEG_G,SEG_B,SEG_C}
#define SEGMENT_FIVE {SEG_A,SEG_F,SEG_G,SEG_C,SEG_D}
#define SEGMENT_SIX  {SEG_A,SEG_F,SEG_E,SEG_D,SEG_C,SEG_G}
#define SEGMENT_SEVEN {SEG_A,SEG_B,SEG_C}
#define SEGMENT_EIGHT {SEG_A,SEG_B,SEG_C,SEG_D,SEG_E,SEG_F,SEG_G}
#define SEGMENT_NINE {SEG_A,SEG_F,SEG_G,SEG_B,SEG_C,SEG_D}
#define SEGMENT_ZERO {SEG_A,SEG_F,SEG_E,SEG_D,SEG_C,SEG_B}

enum SEGMENT {
    SEGS_NOTE,
    SEGS_NUMBER,
    SEGS_PATCH,
    SEGS_SEGMENT_MAX,
};

enum SEG_CHAR {
    SEG_A,
    SEG_B,
    SEG_C,
    SEG_D,
    SEG_E,
    SEG_F,
    SEG_G,
    SEG_ZERO,
    SEG_ONE,
    SEG_TWO,
    SEG_THREE,
    SEG_FOUR,
    SEG_FIVE,
    SEG_SIX,
    SEG_SEVEN,
    SEG_EIGHT,
    SEG_NINE,
    SEG_CHAR_MAX,
};

typedef struct SegmentChar {
    enum SEG_CHAR _segChar;
    // bool _dp;
    int _segTarget[SEG_CHAR::SEG_CHAR_MAX];
    int _segmentSize;
} tagSEGMENTCHAR, tagLPSEGMENTCHAR;

class HardInterFace {
public:
    bool getMidi(LPMIDIDATAS pData);
    void sendMidi(const LPMIDIDATAS data);
    void initMidi(int ch);
    void initPinMode();
    static void timerFuncPinMonitor();
    void ledFlash(int light);
    void setFunction(int pinNo, Common::PIN_KIND kind);
    tagSEGMENTCHAR _segmentChar;
    enum SEGMENT _segmentIndex;

private:
    void inputPin();
    void outputPin();
    void initOutput();
    void segmentInit();
    PinMonitor _pinMon[PINMON_BUF];
    // int _segments[SEGMENT::MAX];
    int _pinMonSize;
    static Common::PINSTATE checkDigitalRead(int read);
    // static bool pinInverseCheck(tagLPPINMON pindata);
    static void pinChange(PinMonitor *pin);
};

