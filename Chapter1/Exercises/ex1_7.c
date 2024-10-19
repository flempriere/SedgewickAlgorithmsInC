/*
Exercise 1-7:
    - show that state of the id array at each stage of reading from 
    sample_data.dat.
    - count the total number of array accesses
    - Using Weighted Quick Union algorithm
*/


#include <stdio.h>
#include <stddef.h>

#define N 10
#define SWAP(x,y) do {  \
    size_t _t = x;      \
    x = y;              \
    y = _t;             \
} while(0)              \

void printArr(size_t len, size_t a[len]);

int main(int argc, char *argv[argc + 1]) {
    size_t id[N];
    size_t sz[N];
    size_t p, q, n_acc = 0;

    for (size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (scanf("%zu %zu\n", &p , &q) == 2) {
        size_t i, j;
        for (i = p; n_acc++, i != id[i]; i = id[i], n_acc++);
        for (j = q; n_acc++, j != id[j]; j = id[j], n_acc++);

        if (i == j) continue;

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];
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
