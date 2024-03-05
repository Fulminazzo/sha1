#ifndef SHA1_SHA1_H
#define SHA1_SHA1_H

#define MESSAGE_SIZE 65536

#include "functions.h"
#include "message.h"

typedef union Message_s {
    uchar bytes[MESSAGE_SIZE];
    WORD words[MESSAGE_SIZE / sizeof(WORD)];
} Message;

#endif //SHA1_SHA1_H
