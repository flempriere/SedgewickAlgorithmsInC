/*
Reads a sequence of pairs of no-negative integers less than N
from standard input.

The pair p q means connect p to q

arr[N] has the property that id[p] and id[q] are equal iff p and q are
connected

Complexity: - Each union is linear in length since
we have to update all entries
            - Each find is constant time, we just test
            equality.
*/

#include <stdio.h>
#include <stddef.h>

#define N 10000

int main() {
    size_t p;
    size_t q;
    size_t id[N];

    for (size_t i = 0; i < N; i++) id[i] = i;
    while(scanf("%zu %zu\n", &p, &q) == 2) {
        if (id[p] == id[q]) continue;
        size_t t = id[p];
        for (size_t i = 0; i < N; i++) {
            if (id[i] == t) id[i] = id[q];
        }
        printf(" %zu %zu\n", p, q);
    }
}