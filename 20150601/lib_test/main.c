#include <stdio.h>

#include "add.h"
#include "sub.h"

int main() {
    printf("1 + 1 = %d\n", add(1, 1));
    printf("1 - 1 = %d\n", sub(1, 1));

    return 0;
}
