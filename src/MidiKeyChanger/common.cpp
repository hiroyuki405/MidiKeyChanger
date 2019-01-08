#include "common.h"



ULONG Common::ULONG_AddValue(ULONG *value, ULONG add)
{
	ULONG rest = 0;
	bool ret = (*value + add >= ULONG_MAX);
	if (ret) {
		*value = 0;
		rest = ULONG_MAX - (*value + add);
	}
	else {
		*value += add;
	}
	return rest;
}
