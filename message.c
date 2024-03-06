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

    for (i = 0; i < length; i++)
        tmp[i / int_size] += src[i] << SHIFT(i);

    // Set separator bit
    tmp[i / int_size] += SEPARATOR << SHIFT(i);
    i++;

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
    ulong length, int_size = sizeof(int);
    ulong i, index;
    unsigned int c, j, *tmp;

    if (size % BYTES_LENGTH != 0) exit(INVALID_LENGTH_PROVIDED);

    index = size / int_size - 1;
    length = ((int *) src)[index] / BITS_PER_BYTE;

    memset(dst, 0, length);
    tmp = (unsigned int *) src;

    for (i = 0; i < length; i++) {
        c = tmp[i / int_size] >> SHIFT(i);
        c = c & 127;
        dst[i] = (char) c;
    }
}