#ifndef SHA1_FUNCTIONS_H
#define SHA1_FUNCTIONS_H

#ifndef WORD
#define WORD unsigned int
#endif

ulong s(ulong x, int n);

ulong f(int t, ulong b, ulong c, ulong d);

long k(int t);

#endif //SHA1_FUNCTIONS_H
