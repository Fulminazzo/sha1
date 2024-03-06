#include "utils.h"

long int power(long int n, long int i) {
    if (i == 0) return 1;
    else if (i <= 1) return n;
    else return n * power(n, i - 1);
}

int chars_to_int(const char *src) {
    int tmp = 0;

    tmp += src[3];
    tmp += src[2] << 8;
    tmp += src[1] << 16;
    tmp += src[0] << 24;

    return tmp;
}