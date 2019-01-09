#include "common.h"

using namespace Common;

ULONG Calc::ULONG_AddValue(ULONG *value, ULONG add) {
    ULONG rest = 0;
    bool ret = (*value + add >= ULONG_MAX);
    if (ret) {
        *value = 0;
        rest = ULONG_MAX - (*value + add);
    } else {
        *value += add;
    }
    return rest;
}

/**
 * リングバッファインクリメント
 * */
int Calc::incrementLing(int index, int max) {
    int ret = 0;
    if (index + 1 >= max) {
        ret = 0;
    } else {
        ret = index + 1;
    }
    return ret;
}

/**
 * リングバッファデクリメント
 * */
int Calc::decrementLing(int index, int max) {
    int ret = 0;
    if (index - 1 < 0) {
        ret = max - 1;
    } else {
        ret = index - 1;
    }
    return ret;
}