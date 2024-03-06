#include "utils.h"

long int power(long int n, long int i) {
    if (i == 0) return 1;
    else if (i <= 1) return n;
    else return n * power(n, i - 1);
}