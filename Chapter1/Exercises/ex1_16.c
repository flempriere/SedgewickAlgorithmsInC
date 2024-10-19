/*
Exercise 1-16 and 1-17
    - Implement full path compression
    - show that state of the id array at each stage of reading from 
    sample_data.dat.
    - count the total number of array accesses
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
    size_t p, q, n_access = 0;

    for (size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (scanf("%zu %zu\n", &p , &q) == 2) {
        size_t i, j;
        //find the root
        for (i = p; n_access += 1, i != id[i]; i = id[i], n_access += 1);

        //traverse tree and compress
        while(p != i) {
            size_t np = id[p];
            n_access += 2;
            id[p] = i;
            p = np;
        }
        //repeat
        for (j = q; n_access += 1, j != id[j]; j = id[j], n_access += 1);

        while (q != j) {
            size_t nq = id[q];
            n_access += 2;
            id[q] = j;
            q = nq;
        }
        if (i == j) continue;

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];
        n_access += 1;
        printf(" %zu %zu\n", p, q);
        printArr(N, id);
    }
    printf("id array accesses: %zu\n", n_access);
    return 0; 
}

void printArr(size_t len, size_t a[len])
{
    for (size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
