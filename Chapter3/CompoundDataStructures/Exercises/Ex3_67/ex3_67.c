/**
 * @file ex3_67.c
 * @author Felix Lempriere
 * @brief Converts matrix from a two-dimensional array to a multilist
 * with nodes for only nonzero values. Implementation is in matrix.c
 * and matrix.h, this file just serves as driver code.
 * @version 0.1
 * @date 2024-12-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Matrix.h"

/**
 * @brief Test driver code for conversion of a matrix to a
 * sparse representation format.
 * 
 * Reads in the number of rows, columns and the probability of
 * an element being zero from the command line.
 * 
 * @param argv[1] rows
 * @param argv[2] columns
 * @param argv[3] probability of matrix element being zero
 * @return EXIT_SUCCESS on successful execution else
 * @return EXIT_FAILURE 
 */
int main(int argc, char* argv[argc]) {
    
    if (!(argc == 4)) {
        fprintf(stderr, "Error: Usage ./%s row col p_zero\n", argv[0]);
        return EXIT_FAILURE;
    }
    size_t row = strtoull(argv[1], nullptr, 0);
    size_t col = strtoull(argv[2], nullptr, 0);
    double p_zero = strtod(argv[3], nullptr);
    if (0.0 > p_zero || p_zero > 1.0) {
        fprintf(stderr, "Error: Probability of element being zero"
            "must be between 0 and 1 (inclusive)\n");
        return EXIT_FAILURE;
    }
    srand(time(nullptr));
    Number** matrix = MATRIXgenerateRandomSparse(row, col, p_zero);
    MATRIXview(row, col, matrix);

    MATRIXnode** sparseMatrix = MATRIXconvertMatrixToSparse(row, col, matrix);
    MATRIXviewSparse(row, sparseMatrix);

    return EXIT_SUCCESS;    
} 