#ifndef SHA1_FUNCTIONS_H
#define SHA1_FUNCTIONS_H

#ifndef WORD
#define WORD unsigned int
#endif

WORD rotate_left(WORD value, int bits);

WORD calculate_f(int t, WORD b, WORD c, WORD d);

WORD get_k(int t);

#endif //SHA1_FUNCTIONS_H
