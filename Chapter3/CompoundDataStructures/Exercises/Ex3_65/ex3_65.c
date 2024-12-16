/**
 * @file ex3_65.c
 * @author Felix Lempriere (you@domain.com)
 * @brief Fills a boolean two-dimensional array a such
 * that a[i][j] is 1 if the gcd of i and j is 1, else 0.
 * 
 * Uses a modified version of malloc2d from Program 3.16
 * to support booleans
 * @version 0.1
 * @date 2024-12-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief swap's the contents of x and y.
 * 
 * @param x first item to be swapped.
 * @param y second item to be swapped.
 * 
 * @warning x and y must be of compatible type.
 * 
 */
#define SWAP(x, y) do { \
    typeof(x) _t = x;   \
    x = y;              \
    y = _t;             \
} while(0)              \



/**
 * @brief Dynamically allocates space for a 2d array
 * of type integer.
 * 
 * @param row
 * @param col 
 * @return int** pointer to the allocated array
 */
bool** malloc2d(size_t row, size_t col);

/**
 * @brief Computes the greatest common divisor of
 * two positive integers i and j
 * 
 * @param i positive integer >= 0
 * @param j positive integer >= 0
 * @return positive integer representing the greatest
 * common divisor of i and j. 
 */
size_t gcd(size_t i, size_t j);
/**
 * @brief Prints out the contents of the @N x @N
 * square array a, using a 1 = true, 0 = false
 * representation.
 * 
 * @param N length of the square array dimensions
 * @param a boolean-valued square array
 */
void printArray(size_t N, bool* a[N]);

/**
 * @brief Generates a boolean array of size @N x @N
 * where a[i][j] = true iff i and j are relatively
 * prime (i.e gcd(i,j) = 1).
 * 
 * @param argv[1] N array dimensions.
 *
 * @return EXIT_SUCCESS on successful execution, else
 * @return EXIT_FAILURE.
 */

int main(int argc, char* argv[argc]) {

    if (argc != 2) {
        fprintf(stderr, "Error, Usage: %s N\n", argv[0]);
        return EXIT_FAILURE;
    }
    size_t N = strtoull(argv[1], nullptr, 0);

    bool** a = malloc2d(N, N);

    for (size_t i = 0; i < N; i++) {
        a[i][i] = (i == 1);
        for (size_t j = 0; j < i; j++) {
            a[i][j] = (gcd(i, j) == 1);
            a[j][i] = a[i][j];
        }
    }

    printArray(N, a);
    return EXIT_SUCCESS;
}

bool** malloc2d(size_t row, size_t col) {
    bool** t = malloc(row * sizeof(typeof(*t)));
    for (row--; row < SIZE_MAX; row--) {
        t[row] = malloc(col * sizeof(typeof(**t)));
    }
    return t;
}

size_t gcd(size_t i, size_t j) {
    while (i != j) {
        if (i < j) SWAP(i,j);
        if (!j) return i;
        i -= j;
    }
    return i;
}


void printArray(size_t N, bool* a[N]) {
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
    for (size_t i = 0; i < N; i++) {
        printf("%zu\t|", i);
        for (size_t j = 0; j < N; j++) {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
}
