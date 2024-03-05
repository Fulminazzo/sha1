#ifndef SHA1_MESSAGE_H
#define SHA1_MESSAGE_H

#ifndef BITS_PER_BYTE
#define BITS_PER_BYTE 8
#endif

#define BYTES_LENGTH 64
#define BYTES_SIZE_LENGTH 8
#define SEPARATOR 128
#define PADDING 0

#define INVALID_LENGTH_PROVIDED 100

#include "utils.h"

/**
 * @return the final size of the message
 */
ulong preprocess_message(uchar *dst, const char *src);

void deprocess_message(char *dst, const uchar *src, ulong size);

#endif //SHA1_MESSAGE_H
