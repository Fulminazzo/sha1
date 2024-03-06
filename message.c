#include "message.h"
#include <string.h>
#include <stdlib.h>

#define SHIFT(i) ((int_size - i % int_size - 1) * BITS_PER_BYTE)

ulong preprocess_message(uchar *dst, const char *src) {
    const ulong length = strlen(src), int_size = sizeof(unsigned int);
    ulong i, bits;
    unsigned int *tmp;

    memset(dst, 0, length);
    tmp = (unsigned int *) dst;

    for (i = 0; i < length; i++) {
        tmp[i / int_size] += src[i] << SHIFT(i);
    }

    // Set separator bit
    tmp[i / int_size] += SEPARATOR << SHIFT(i);

    // Avoid override of current word
    while (i % int_size != 0) i++;

    // Set padding
    while ((i + BYTES_SIZE_LENGTH) % BYTES_LENGTH != 0)
        dst[i++] = (unsigned char) PADDING;

    // Convert length to bits
    bits = length * BITS_PER_BYTE;

    tmp[i / int_size] = 0;
    tmp[i / int_size + 1] = bits;

    return i + BYTES_SIZE_LENGTH;
}

void deprocess_message(char *dst, const uchar *src, ulong size) {
    ulong length;
    ulong i, value, shift;

    if (size % BYTES_LENGTH != 0) exit(INVALID_LENGTH_PROVIDED);

    length = 0;
    for (i = 0; i < BYTES_SIZE_LENGTH; i++) {
        value = src[size - i - 1];
        shift = i * sizeof(ulong);
        value = value << shift;
        length += value;
    }
    length /= BITS_PER_BYTE;

    for (i = 0; i < length; i++) dst[i] = src[i];
}