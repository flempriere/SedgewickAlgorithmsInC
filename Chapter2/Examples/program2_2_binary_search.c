/*
    Program 2.1 Binary search

    Assuming a is a sorted array, then if a[i] > v, v must be to the left of a[i]
    in the array, conversely if a[i] < v, v must be to the right.

    Binary search:
        recursively split the array at the midpoint (l + r) / 2 and check
        which half v is in until a[midpoint] = v or the array to check is empty

    returns the index of v if found, else SIZE_MAX
 */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define N 10

size_t search(int v, size_t l, size_t r, int a[r+1]);

int main(int argc, char* argv[argc + 1]) {
    int a[N] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    for (int i = 0; i <= N; i++) {
        size_t idx = search(i*10, 0, N-1, a);
        if (idx != SIZE_MAX) {
            printf("v: %d, i: %zu, a[i]: %d\n", i, idx, a[idx]);
        } else {
            printf("v: %d, i: NOT_FOUND\n", i);
        }
    }
}

size_t search(int v, size_t l, size_t r, int a[r+1]) {
    while(r >= l) {
        size_t m = (l + r)/2; 
        if (v == a[m]) return m;
        if (v < a[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return SIZE_MAX;
}