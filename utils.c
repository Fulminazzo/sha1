#include "utils.h"

long int power(long int n, long int i) {
    if (i == 0) return 1;
    else if (i <= 1) return n;
    else return n * power(n, i - 1);
}

void write_to_string(uchar *dst, ulong num, ulong from) {
    const ulong char_size = sizeof(uchar);
    const ulong num_size = sizeof(ulong);
    const ulong to_print = num_size / char_size;
    const ulong mask = power(2, (long int) char_size * BITS_PER_BYTE) - 1;
    ulong shift, i, value;

    for (i = 0; i < to_print; i += char_size) {
        shift = to_print - i - 1;
        shift *= num_size;
        value = (num >> shift) & mask;
        dst[from + i] = value;
    }
}

int chars_to_int(const char *src) {
    int tmp = 0;

    tmp += src[3];
    tmp += src[2] << 8;
    tmp += src[1] << 16;
    tmp += src[0] << 24;

    return tmp;
}