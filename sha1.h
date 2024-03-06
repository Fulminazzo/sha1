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
    uchar bytes[MESSAGE_SIZE];
    WORD words[MESSAGE_SIZE / sizeof(WORD)];
} Message;

typedef struct SHA1vars_s {
    ulong a;
    ulong b;
    ulong c;
    ulong d;
    ulong e;
} SHA1vars;

#endif //SHA1_SHA1_H
