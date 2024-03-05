#include "functions.h"

WORD s(WORD x, int n) {
    return (x << n) | (x >> (32 - n));
}

long k(int t) {
    if (0 <= t && t<= 19) return 0x5A827999;
    if (20 <= t && t<= 39) return 0x6ED9EBA1;
    if (40 <= t && t<= 59) return 0x8F1BBCDC;
    if (60 <= t && t<= 79) return 0xCA62C1D6;
    return -1;
}