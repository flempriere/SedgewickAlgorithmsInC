/**
 * @file two_dimArrayAllocation.c
 * @brief Dynamically allocates the memory for a
 * two-dimensional array, as an array of arrays.
 * 
 * We first allocate an array of pointers, then
 * allocate memory for each row.
 * 
 * malloc2d(M,N) allocates an M by N integer array
 * @version 0.1
 * @date 2024-12-01
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Dynamically allocates space for a 2d array
 * of type integer.
 * 
 * @param row
 * @param col 
 * @return int** pointer to the allocated array
 */
int** malloc2d(size_t row, size_t col);

/**
 * @brief Demonstrates malloc2d by allocating a
 * M by N 2D array of integers and printing out
 * the result.
 * 
 * @param argv[0] M
 * @param argv[1] N 
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc]) {

    if (argc != 3) {
        fprintf(stderr, "Error: Usage is %s M N\n", argv[0]);
    }

    size_t M = strtoull(argv[1], nullptr, 0);
    size_t N = strtoull(argv[2], nullptr, 0);

    //populate array
    int** matrix = malloc2d(M, N);
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) {
            matrix[i][j] = i*N + j;
        }
    }
    //print header
    printf("\t|");
    for (size_t i = 0; i < N; i++) {
        printf(" %zu ", i);
    }
    printf("\n\t ");
    for (size_t i = 0; i < N; i++) {
        printf("___");
    }
    printf("\n");

    //print array
    for (size_t i = 0; i < M; i++) {
        printf("%zu\t|", i);
        for (size_t j = 0; j < N; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}

int** malloc2d(size_t row, size_t col) {
    int** t = malloc(row * sizeof(typeof(*t)));
    for (row--; row < SIZE_MAX; row--) {
        t[row] = malloc(col * sizeof(typeof(**t)));
    }
    return t;
}
