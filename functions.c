#include "functions.h"

WORD s(WORD x, int n) {
    return (x << n) | (x >> (32 - n));
}