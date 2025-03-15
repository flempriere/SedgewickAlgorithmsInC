/**
 * @file matrix.h
 * @author Felix Lempriere
 * @brief Interface for matrix and sparse matrix represented as
 * 2d arrays and linked lists respectively. Extends the solution
 * in Ex 3.67 to include matrix multiplication.
 * 
 * A key change is to for code cleanliness and to ensure that we
 * have compatible matrix dimensions we introduce the higher
 * level sparseMatrix structure to wrap the linkedlist representation
 * with some bookkeeping.
 * 
 * @version 0.1
 * @date 2024-12-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 #pragma once
 #include <stdlib.h>

/**
 * @brief Generise matrix element
 * 
 */
typedef int Number;

/**
 * @brief Allocate a 2d array
 * 
 * @param row number of rows
 * @param col number of columns
 * @return Number** pointer to matrix stored in m[row][col].
 */
Number** MATRIXinit(size_t row, size_t col);

/**
 * @brief Print out a representation of a matrix represented
 * using a 2d array.
 * 
 * @param row number of rows in the matrix
 * @param col number of columns
 * @param a pointer to the matrix
 */
void MATRIXview(size_t row, size_t col, Number* a[row]);

/**
 * @brief Generate a spare matrix represented using a 2d array
 * 
 * @param row number of rows
 * @param col number of columns
 * @param p_zero probability of any element being zero
 * @return Number** 
 */
Number** MATRIXgenerateRandomSparse(size_t row, size_t col, double p_zero);

/**
 * @brief structure for a sparse matrix element.
 * 
 * Node contains a matrix element value, a record of the
 * column index and a pointer to the next node.
 * 
 */
typedef struct MATRIXnode MATRIXnode;

struct MATRIXnode {
    Number val;
    size_t col;
    MATRIXnode* next;
};

typedef struct MATRIXsparseMatrix MATRIXsparseMatrix;

struct MATRIXsparseMatrix {
    size_t row;
    size_t col;
    MATRIXnode** m;
};

/**
 * @brief Converts a 2d array matrix representation to a
 * corresponding linked list sparse matrix representation.
 * 
 * @param row number of rows
 * @param col number of columns
 * @param a pointer the 2d array matrix
 * @return node** pointer to sparse matrix on success else
 * @return nullptr
 */
MATRIXsparseMatrix* MATRIXconvertMatrixToSparse(size_t row, size_t col, Number* a[row]);

/**
 * @brief Prints out a representation of matrix using a
 * sparse matrix linked list representation
 * 
 * @param a pointer to the sparse matrix
 */
void MATRIXviewSparse(MATRIXsparseMatrix* a);

/**
 * @brief multiples two sparse matrices together, allocating
 * memory for a new sparse matrix. The client is responsible
 * for managing the memory of the new array.
 * 
 * @param m1 
 * @param m2 
 * @return sparseMatrix* on success, else nullptr
 */
MATRIXsparseMatrix* MATRIXsparseMatMul(MATRIXsparseMatrix* m1, MATRIXsparseMatrix* m2);