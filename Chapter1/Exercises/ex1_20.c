/*
Exercise 1-20:
    - Modify Weighted Union to use the 'height' of the tree
*/


#include <stdio.h>
#include <stddef.h>

#define N 10
#define SWAP(x,y) do {  \
    size_t _t = x;      \
    x = y;              \
    y = _t;             \
} while(0)              \

#define MAX(x,y) ((x) > (y)) ? (x) : (y) 

void printArr(size_t len, size_t a[len]);

int main(int argc, char *argv[argc + 1]) {
    size_t id[N];
    size_t sz[N];
    size_t p, q, n_acc = 0;

    for (size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 0;
    }
    while (scanf("%zu %zu\n", &p , &q) == 2) {
        size_t i, j;
        for (i = p; n_acc++, i != id[i]; i = id[i], n_acc++);
        for (j = q; n_acc++, j != id[j]; j = id[j], n_acc++);

        if (i == j) continue;

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] = MAX(sz[i], sz[j] + 1);
        n_acc++;
        printf(" %zu %zu\n", p, q);
        printArr(N, id);
    }
    printf("Number of id array accesses: %zu\n", n_acc);
    return 0;
}

void printArr(size_t len, size_t a[len])
{
    for (size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
