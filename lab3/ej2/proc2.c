#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if (x >= 0) {
        *y = x;
    }
    else {
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;
    int *p = NULL;
    a = -10;
    p = &res;
    absolute(a, p);
    printf("res = %d\n", res);
    return EXIT_SUCCESS;
}

