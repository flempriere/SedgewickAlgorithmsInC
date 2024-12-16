/**
 * @file ex3_63.c
 * @author Felix Lempriere
 * @brief Dynamically allocates the memory for a
 * three-dimensional array, as a set of nested arrays.
 * 
 * We first allocate an array of pointers to square arrays,
 * then perform the square array allocation as for malloc2d
 * 
 * malloc3d(L, M, N) allocates an L by M by N integer array
 * @version 0.1
 * @date 2024-12-15
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Dynamically allocates space for a 3d array
 * of type integer.
 * 
 * @param row
 * @param col
 * @param depth
 * @return int*** pointer to the allocated array
 */
int*** malloc3d(size_t row, size_t col, size_t depth);

/**
 * @brief Demonstrates malloc3d by allocating a
 * L by M by N 3D array of integers and printing out
 * the result.
 * 
 * @param argv[0] L
 * @param argv[1] M
 * @param argv[2] N 
 * @return EXIT_SUCCESS on success else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc]) {

    if (argc != 4) {
        fprintf(stderr, "Error: Usage is %s L M N\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t L = strtoull(argv[1], nullptr, 0);
    size_t M = strtoull(argv[2], nullptr, 0);
    size_t N = strtoull(argv[3], nullptr, 0);

    //populate array
    int*** matrix = malloc3d(L, M, N);
    for (size_t i = 0; i < L; i++) {
        for (size_t j = 0; j < M; j++) {
            for (size_t k = 0; k < N; k++) {
                matrix[i][j][k] = i*(M*N) + j * N + k;
            }
        }
    }
    //print header
    for (size_t i = 0; i < L; i++) {
        printf("L=%zu\t|", i);
        for (size_t j = 0; j < N; j++) {
            printf("%4zu", j);
        }
        printf("\n\t ");
        for (size_t j = 0; j < N; j++) {
            printf("____");
        }
        printf("\n");
        //print array
        for (size_t j = 0; j < M; j++) {
            printf("%zu\t|", j);
            for (size_t k = 0; k < N; k++) {
                printf("%4d", matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}

int*** malloc3d(size_t row, size_t col, size_t depth) {
    int*** t = malloc(row * sizeof(typeof(*t)));
    for (row--; row < SIZE_MAX; row--) {
        t[row] = malloc(col * sizeof(typeof(**t)));
        for (size_t i = 0; i < col; i++) {
            t[row][i] = malloc(depth * sizeof(typeof(***t)));
        }
    }
    return t;
}
