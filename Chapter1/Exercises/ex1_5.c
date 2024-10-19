/*
Exercise 1-5:
    - show that state of the id array at each stage of reading from 
    sample_data.dat.
    - count the total number of array accesses
    - Using Quick Union algorithm
*/


#include <stdio.h>
#include <stddef.h>

#define N 10

void printArr(size_t len, size_t a[len]);

int main(void) {
    size_t p;
    size_t q;
    size_t n_acc = 0;
    size_t id[N];

    for (size_t i = 0; i < N; i++) id[i] = i;
    while(scanf("%zu %zu\n", &p, &q) == 2) {

        size_t i, j;

        for (i = p; n_acc++, i != id[i]; i = id[i], n_acc++);
        for (j = q; n_acc++, j != id[j]; j = id[j], n_acc++);
        if (i == j) continue;
        id[i] = j;
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
