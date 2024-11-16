/*
Exercise 3.33
Modify Program 3.9 that uses an array of indices to implement
the linked list
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef size_t key;
typedef size_t link;

void printState(size_t N, key it[N], link nxt[N]);

int main(int argc, char* argv[argc+1]) {
    //idx i holds the i-th node.
    //zero the arrays
    key item[MAX_N] = {};
    link next[MAX_N] = {};

    if (argc != 3) {
        fprintf(stderr, "Error: requires args N M\n");
        return EXIT_FAILURE;
    }
    size_t N = strtoull(argv[1], nullptr, 0);
    size_t M = strtoull(argv[2], nullptr, 0);

    for (key i = 0; i < N; i++) {
        item[i] = N - i;
        next[i] = (i + 1) % N;
    }
    link x = N;
    size_t n = N;
    while (x != next[x]) {
        printState(n, item, next);
        for (link i = 1; i < M; i++) x = next[x];
        printf("%2zu\n", item[next[x]]);
        next[x] = next[next[x]];
        N--;
    }
    return EXIT_SUCCESS
}

void printState(size_t N, key it[N], link nxt[N]) {
    printf("Item: ");
    for (size_t i = 0; i < N; i++) {
        printf("%2zu ", it[i]);
    }
    printf("\nNext: ");
    for (size_t i = 0; i < N; i++) {
        printf("%2zu ", nxt[i]);
    }
    printf("\n");
}