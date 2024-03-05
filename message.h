#ifndef SHA1_MESSAGE_H
#define SHA1_MESSAGE_H

#define BITS_PER_BYTE 8

#define BYTES_LENGTH 64
#define BYTES_SIZE_LENGTH 8
#define SEPARATOR 128
#define PADDING 0

void preprocess_message(char *dst, const char *src);

#endif //SHA1_MESSAGE_H
