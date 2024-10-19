/*
Quick Union solution

- Unions are constant time
- finds are linear time

- Unions achieved by building trees, connect a[p] -> q etc. 
- Find now requires us to traverse the root
- Quick Union is generally faster than Quick Find -> don't need to traverse
- all array.
*/

#include <stdio.h>
#include <stddef.h>

#define N 10000

int main(void) {
    size_t p;
    size_t q;
    size_t id[N];

    for (size_t i = 0; i < N; i++) id[i] = i;
    while(scanf("%zu %zu\n", &p, &q) == 2) {

        size_t i, j;

        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        if (i == j) continue;
        id[i] = j;
        printf(" %zu %zu\n", p, q);
    }
    return 0;
}