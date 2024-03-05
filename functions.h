#ifndef SHA1_FUNCTIONS_H
#define SHA1_FUNCTIONS_H

#define WORD int

WORD s(WORD x, int n);

WORD f(int t, WORD b, WORD c, WORD d);

long k(int t);

#endif //SHA1_FUNCTIONS_H
