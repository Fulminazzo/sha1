#include "message.h"
#include <string.h>

int power(const int n, const int i) {
    if (i == 0) return 1;
    else if (i <= 1) return n;
    else return n * power(n, i - 1);
}

void preprocess_message(char *dst, const char *src) {
    const size_t length = strlen(src);
    size_t i, bits;
    const int mask = power(2, BITS_PER_BYTE) - 1;
    int shift;

    for (i = 0; i != length; i++) dst[i] = src[i];

    // Set separator bit
    dst[i++] = (char) SEPARATOR;

    while ((i + BYTES_SIZE_LENGTH) % BYTES_LENGTH != 0)
        dst[i++] &= PADDING;

    // Convert length to bits
    bits = length * BITS_PER_BYTE;

    for (int j = 0; j < BYTES_SIZE_LENGTH; j++) {
        shift = BYTES_SIZE_LENGTH - j - 1;
        shift *= BITS_PER_BYTE;
        dst[i + j] = (char) (bits & ((size_t) mask << shift));
    }
}