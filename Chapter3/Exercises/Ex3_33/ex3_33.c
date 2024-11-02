/*
Exercise 3.31
Run Program 3.9 plot the results for M = 10, with N = 2 to 1000.
*/

#include <stdlib.h>
#include <stdio.h>

#define N_MAX 9

typedef size_t node;

size_t item[N_MAX];
node next[N_MAX];

void printState(size_t i);

int main(int argc, char* argv[argc+1]) {

    size_t M = 5;

    for (size_t i = 0; i < N_MAX; i++) {
        item[i] = N_MAX -  i;
        next[i] = (i + 1) % N_MAX;
    }
    size_t i = 0;
    while (i != next[i]) {
        for (size_t k = 1; k < M; k++) i = next[i];
        next[i] = next[next[i]];
        printState(i);
    }
    return 0;
}

void printState(size_t i) {

    printf("%4zu\t", i);
    for (size_t j = 0; j < N_MAX; j++) {
        printf("%zu ", item[j]);
    }
    printf("\n%4s\t", "");
    for (size_t j = 0; j < N_MAX; j++) {
        printf("%zu ", next[j]);
    }
    printf("\n");
}