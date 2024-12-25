/**
 * @file ex3_68.c
 * @author Felix Lempriere
 * @brief Generates and multiples two sparse matrix
 * representations together. Implementation is in matrix.c
 * and matrix.h, this file just serves as driver code.
 * @version 0.1
 * @date 2024-12-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"

/**
 * @brief Test driver code for sparse matrix multiplication
 * 
 * Reads in the number of rows, columns for the first matrix and the probability of
 * an element being zero from the command line. The dimensions of the
 * second matrix are transposed.
 * 
 * @param argv[1] rows of the first matrix and columns of the second
 * @param argv[2] columns of thefirst matrix and columns of the second
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

    //generate first matrix
    printf("Generating first random matrix: \n");
    Number** matrix = generateRandomSparse(row, col, p_zero);
    viewArray(row, col, matrix);

    sparseMatrix* m1 = convertMatrixToSparse(row, col, matrix);
    viewSparse(m1);

    //generate second matrix
    printf("Generating second random matrix: \n");
    Number** matrix2 = generateRandomSparse(col, row, p_zero);
    viewArray(col, row, matrix2);

    sparseMatrix* m2 = convertMatrixToSparse(col, row, matrix2);
    viewSparse(m2);

    printf("Matrix product: \n");
    sparseMatrix* product = sparseMatMul(m1, m2);
    viewSparse(product);


    return EXIT_SUCCESS;    
}

