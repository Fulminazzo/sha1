#include "sha1.h"

#include <stdio.h>
#include <string.h>

void init_vars(SHA1vars *h) {
    h->a = 0x67452301;
    h->b = 0xEFCDAB89;
    h->c = 0x98BADCFE;
    h->d = 0x10325476;
    h->e = 0xC3D2E1F0;
}

void print_starting_point(unsigned int *tmp) {
    printf("Printing starting point: ");
    for (int i = 0; i < 16; i++)
        printf("%02x ", tmp[i]);
    printf("\n");
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
    const char tmp[MESSAGE_SIZE];
    ulong length, ws, i;
    const ulong words_size = (sizeof(WORD) * BITS_PER_BYTE);
    const ulong chars_per_iteration = WORDS_PER_ITERATION * words_size / BITS_PER_BYTE / sizeof(uchar);

    init_vars(&h);
    length = preprocess_message(tmp, src) * BITS_PER_BYTE;
    printf("Length: %d\n", length);
//    if(1) return;

    ws = length / words_size / WORDS_PER_ITERATION;
    messages = malloc(sizeof(messages) * ws);

    for (i = 0; i < ws; i++) {
        for (int j = 0; j < WORDS_PER_ITERATION; j++)
            messages[i].words[i] = ((int*) tmp)[i * WORDS_PER_ITERATION + j];
//        for (int j = 0; j < chars_per_iteration; j++) {
//            messages[i].bytes[j] = tmp[i * chars_per_iteration + j];
//        }
        printf("messages[0]: %02x\n", messages[i].words[0]);
        printf("messages[1]: %02x\n", messages[i].words[1]);
        printf("messages[2]: %02x\n", messages[i].words[2]);

        //TODO: remove this
        memset(messages[i].words, 0, 32);
        messages[i].words[0] = 0x61626380;
        messages[i].bytes[5] = 0;
        messages[i].words[15] = 0x18;
        print_starting_point(messages[i].words);

        computeSHA1_M(&(messages[i]), &h);

        for (int j = 0; j < chars_per_iteration; j++)
            dst[i * chars_per_iteration + j] = (char) messages[i].bytes[j];
    }

    printf("%08x", h.a);
    printf("%08x", h.b);
    printf("%08x", h.c);
    printf("%08x", h.d);
    printf("%08x", h.e);
    printf("\n");

    free(messages);
}
