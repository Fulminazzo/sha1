#ifndef SHA1_FUNCTIONS_H
#define SHA1_FUNCTIONS_H

#include "utils.h"

ulong s(ulong x, int n);

ulong f(int t, ulong b, ulong c, ulong d);

long k(int t);

#endif //SHA1_FUNCTIONS_H
