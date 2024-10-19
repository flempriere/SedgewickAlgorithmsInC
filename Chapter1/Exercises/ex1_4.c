/*
Exercise 1-4:
    - show that state of the id array at each stage of reading from 
    sample_data.dat.
    - count the total number of array accesses
    - Using Quick Find algorithm
*/

#include <stdio.h>
#include <stddef.h>

#define N 10

void printArr(size_t len, size_t a[len]);

int main() {
    size_t p;
    size_t q;
    size_t id[N];
    size_t n_accesses = 0;

    for (size_t i = 0; i < N; i++) id[i] = i;
    while(scanf("%zu %zu\n", &p, &q) == 2) {
        if (id[p] == id[q]) {n_accesses += 2;}
        size_t t = id[p];
        for (size_t i = 0; i < N; i++) {
            n_accesses += 1;
            if (id[i] == t) {id[i] = id[q]; n_accesses += 2;}
        }
        printf(" %zu %zu\n", p, q);
        printArr(N, id);
    }
    printf("Total array acceses: %zu\n", n_accesses);
}

void printArr(size_t len, size_t a[len])
{
    for (size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
