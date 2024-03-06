#include "sha1.h"
#include "message.h"

#include <stdlib.h>

void init_vars(SHA1vars *h) {
    h->a = 0x67452301;
    h->b = 0xEFCDAB89;
    h->c = 0x98BADCFE;
    h->d = 0x10325476;
    h->e = 0xC3D2E1F0;
}

void computeSHA1_M(Message *message, SHA1vars *h) {
    SHA1vars tmp;
    int t;
    WORD val, temp;

    tmp.a = h->a;
    tmp.b = h->b;
    tmp.c = h->c;
    tmp.d = h->d;
    tmp.e = h->e;

    for (t = 0; t < ITERATIONS; t++) {

        // Extend words to 80.
        if (t >= 32) {
            val = message->words[t - 6];
            val ^= message->words[t - 16];
            val ^= message->words[t - 28];
            val ^= message->words[t - 32];
            val = rotate_left(val, 2);
        } else if (t >= 16) {
            val = message->words[t - 3];
            val ^= message->words[t - 8];
            val ^= message->words[t - 14];
            val ^= message->words[t - 16];
            val = rotate_left(val, 1);
        } else val = message->words[t];
        message->words[t] = val;


        temp = calculate_f(t, tmp.b, tmp.c, tmp.d);
        temp = rotate_left(tmp.a, 5) + temp + tmp.e + get_k(t) + message->words[t];

        tmp.e = tmp.d;
        tmp.d = tmp.c;
        tmp.c = rotate_left(tmp.b, 30);
        tmp.b = tmp.a;
        tmp.a = temp;
    }

    h->a += tmp.a;
    h->b += tmp.b;
    h->c += tmp.c;
    h->d += tmp.d;
    h->e += tmp.e;
}

void computeSHA1(char *dst, const char *src) {
    SHA1vars h;
    Message *messages;
    uchar tmp[MESSAGE_SIZE];
    ulong message_length, messages_size, i, j;
    const ulong word_size = (sizeof(WORD) * BITS_PER_BYTE);

#define WORD_PTR(ptr) ((WORD*) ptr)

    init_vars(&h);

    message_length = preprocess_message(tmp, src) * BITS_PER_BYTE;

    messages_size = message_length / word_size / WORDS_PER_ITERATION;
    messages = malloc(sizeof(Message) * messages_size);

    for (i = 0; i < messages_size; i++) {
        for (j = 0; j < WORDS_PER_ITERATION; j++)
            messages[i].words[j] = WORD_PTR(tmp)[i * WORDS_PER_ITERATION + j];

        computeSHA1_M(&(messages[i]), &h);
    }

    WORD_PTR(dst)[0] = h.a;
    WORD_PTR(dst)[1] = h.b;
    WORD_PTR(dst)[2] = h.c;
    WORD_PTR(dst)[3] = h.d;
    WORD_PTR(dst)[4] = h.e;

    free(messages);
}