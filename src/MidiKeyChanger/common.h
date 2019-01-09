// common.h
#pragma once
#include "arduino.h"
#include "limits.h"
#include "debugPrint.h"
#include <string.h>

#define ULLONG unsigned long long
#define ULONG unsigned long
#define TRUE (1==1)
#define FALSE (1!=1)
#define LOOP_INTERVAL_US 5 
#define NULL_PTR_CEHCK(ptr) (ptr==NULL)

#define CHATTERING_COUNT 10
#define CHATTERING_SPAN 1
#define CHATTERING_FLAG TRUE
#define PINMON_BUF 10

namespace Common {

    enum PIN_KIND {
        PIN_PREV,
        PIN_NEXT,
        MONITOR_SIZE,
    };

    enum PINSTATE {
        ON = LOW,
        OFF = HIGH,
    };

    enum PINMON_STATE {
        NONE,
        UNSET,
        SET,
    };

    enum NOTE_NUMBER {
        //initialize
        ZERO = -1,
        //ovtave -2
        NOTE_Cd2,
        NOTE_Cd2s,
        NOTE_Dd2,
        NOTE_Dd2s,
        NOTE_Ed2,
        NOTE_Fd2,
        NOTE_Fd2s,
        NOTE_Gd2,
        NOTE_Gd2s,
        NOTE_Ad2,
        NOTE_Ad2s,
        NOTE_Bd2,
        //octave -1
        NOTE_Cd1,
        NOTE_Cd1s,
        NOTE_Dd1,
        NOTE_Dd1s,
        NOTE_Ed1,
        NOTE_Fd1,
        NOTE_Fd1s,
        NOTE_Gd1,
        NOTE_Gd1s,
        NOTE_Ad1,
        NOTE_Ad1s,
        NOTE_Bd1,
        //octave 0
        NOTE_C0,
        NOTE_C0s,
        NOTE_D0,
        NOTE_D0s,
        NOTE_E0,
        NOTE_F0,
        NOTE_F0s,
        NOTE_G0,
        NOTE_G0s,
        NOTE_A0,
        NOTE_A0s,
        NOTE_B0,
        //octave 1
        NOTE_C1,
        NOTE_C1s,
        NOTE_D1,
        NOTE_D1s,
        NOTE_E1,
        NOTE_F1,
        NOTE_F1s,
        NOTE_G1,
        NOTE_G1s,
        NOTE_A1,
        NOTE_A1s,
        NOTE_B1,
        //octave 2
        NOTE_C2,
        NOTE_C2s,
        NOTE_D2,
        NOTE_D2s,
        NOTE_E2,
        NOTE_F2,
        NOTE_F2s,
        NOTE_G2,
        NOTE_G2s,
        NOTE_A2,
        NOTE_A2s,
        NOTE_B2,
        //octave 3
        NOTE_C3,
        NOTE_C3s,
        NOTE_D3,
        NOTE_D3s,
        NOTE_E3,
        NOTE_F3,
        NOTE_F3s,
        NOTE_G3,
        NOTE_G3s,
        NOTE_A3,
        NOTE_A3s,
        NOTE_B3,
        //octave 4
        NOTE_C4,
        NOTE_C4s,
        NOTE_D4,
        NOTE_D4s,
        NOTE_E4,
        NOTE_F4,
        NOTE_F4s,
        NOTE_G4,
        NOTE_G4s,
        NOTE_A4,
        NOTE_A4s,
        NOTE_B4,
        //octave 5
        NOTE_C5,
        NOTE_C5s,
        NOTE_D5,
        NOTE_D5s,
        NOTE_E5,
        NOTE_F5,
        NOTE_F5s,
        NOTE_G5,
        NOTE_G5s,
        NOTE_A5,
        NOTE_A5s,
        NOTE_B5,
        //octave 6
        NOTE_C6,
        NOTE_C6s,
        NOTE_D6,
        NOTE_D6s,
        NOTE_E6,
        NOTE_F6,
        NOTE_F6s,
        NOTE_G6,
        NOTE_G6s,
        NOTE_A6,
        NOTE_A6s,
        NOTE_B6,
        //octave 7
        NOTE_C7,
        NOTE_C7s,
        NOTE_D7,
        NOTE_D7s,
        NOTE_E7,
        NOTE_F7,
        NOTE_F7s,
        NOTE_G7,
        NOTE_G7s,
        NOTE_A7,
        NOTE_A7s,
        NOTE_B7,
        //octave 8
        // NOTE_C8,
        // NOTE_C8s,
        // NOTE_D8,
        // NOTE_D8s,
        // NOTE_E8,
        // NOTE_F8,
        // NOTE_F8s,
        // NOTE_G8,
        // NOTE_G8s,
        // NOTE_A8,
        // NOTE_A8s,
        // NOTE_B8,
        //MAX
        NOTE_MAX
    };

    class Calc {
    public:
        static ULONG ULONG_AddValue(ULONG *value, ULONG add);
        static int incrementLing(int index, int max);
        static int decrementLing(int index, int max);
    };
}
