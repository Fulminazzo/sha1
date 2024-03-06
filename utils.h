#ifndef SHA1_UTILS_H
#define SHA1_UTILS_H

#ifndef BITS_PER_BYTE
#define BITS_PER_BYTE 8
#endif

#define uchar unsigned char
#define ulong long

long int power(long int n, long int i);

void write_to_string(uchar *dst, ulong num, ulong from);

/**
 * Converts the given array of character into an integer.
 * Takes into account the Little-Endian convention.
 */
int chars_to_int(const char *src);

#endif //SHA1_UTILS_H
