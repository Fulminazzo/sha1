#ifndef SHA1_UTILS_H
#define SHA1_UTILS_H

#ifndef BITS_PER_BYTE
#define BITS_PER_BYTE 8
#endif

#define uchar unsigned char
#define ulong unsigned long int

long int power(long int n, long int i);

void write_to_string(uchar *dst, ulong num, ulong from);

#endif //SHA1_UTILS_H
