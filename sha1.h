#ifndef SHA1_SHA1_H
#define SHA1_SHA1_H

#define MESSAGE_SIZE 65536
#define WORDS_PER_ITERATION 16
#define ITERATIONS 80

#ifndef WORD
#define WORD unsigned int
#endif

#include "functions.h"
#include "message.h"

typedef union Message_s {
    uchar bytes[ITERATIONS * sizeof(WORD) / sizeof(uchar)];
    WORD words[ITERATIONS];
} Message;

typedef struct SHA1vars_s {
    WORD a;
    WORD b;
    WORD c;
    WORD d;
    WORD e;
} SHA1vars;

void computeSHA1(char *dst, const char *src);

#endif //SHA1_SHA1_H
