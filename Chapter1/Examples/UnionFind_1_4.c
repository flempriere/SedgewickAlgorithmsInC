/*
Weighted Quick Union with path compression
- 
*/

#include <stdio.h>
#include <stddef.h>

#define N 10000
#define SWAP(x,y) do {  \
    size_t _t = x;      \
    x = y;              \
    y = _t;             \
} while(0)              \


int main(int argc, char *argv[argc + 1]) {
    size_t id[N];
    size_t sz[N];
    size_t p, q;

    for (size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (scanf("%zu %zu\n", &p , &q) == 2) {
        size_t i, j;
        for (i = p; i != id[i]; i = id[i]) {id[i] = id[id[i]];}
        for (j = q; j != id[j]; j = id[j]) {id[j] = id[id[j]];}

        if (i == j) continue;

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];
        printf(" %zu %zu\n", p, q);
    }
    return 0; 
}