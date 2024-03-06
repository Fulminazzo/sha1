#include "message.h"
#include <string.h>
#include <stdlib.h>

ulong preprocess_message(uchar *dst, const char *src) {
    const ulong length = strlen(src);
    ulong i, bits;
    int c, *tmp;

    tmp = (int *) dst;
    for (i = 0; i < length; i += sizeof(int)) {
        c = chars_to_int(src + i);
        tmp[i / sizeof(int)] = c;
    }
    if (i > length + 1) i = length + 1;

    // Set separator bit
    dst[0] = (char) SEPARATOR;

    while ((i + BYTES_SIZE_LENGTH) % BYTES_LENGTH != 0)
        dst[i++] &= PADDING;

    // Convert length to bits
    bits = length * BITS_PER_BYTE;

    write_to_string(dst, bits, i);

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