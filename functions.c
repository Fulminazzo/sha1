#include "functions.h"

ulong s(ulong x, int n) {
    return (x << n) | (x >> (32 - n));
}

ulong f(int t, ulong b, ulong c, ulong d) {
    if (0 <= t && t <= 19)
        return (b & c) | ((!b) & d);
    if (20 <= t && t <= 39)
        return b ^ c ^ d;
    if (40 <= t && t <= 59)
        return (b & c) | (b & d) | (c & d);
    if (60 <= t && t <= 79)
        return b ^ c ^ d;
    return -1;
}

long k(int t) {
    if (0 <= t && t <= 19) return 0x5A827999;
    if (20 <= t && t <= 39) return 0x6ED9EBA1;
    if (40 <= t && t <= 59) return 0x8F1BBCDC;
    if (60 <= t && t <= 79) return 0xCA62C1D6;
    return -1;
}