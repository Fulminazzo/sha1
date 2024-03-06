The following is a simple implementation of the **SHA1** algorithm in **C**.

It is one of my first attempts at learning this programming language, so I **advise against using it in actual production** because of bugs and memory leaks that might be present.

To use it, simply include _sha1.h_:
```c
#include "sha1.h"

/* ... */

int main() {
    char *src = "Crypt me!";
    char dst[MESSAGE_SIZE];
    
    computeSHA1(dst, src);
}
```