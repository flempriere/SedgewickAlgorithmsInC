/**
 * @file matrix.h
 * @author Felix Lempriere
 * @brief Interface for matrix and sparse matrix represented as
 * 2d arrays and linked lists respectively.
 * @version 0.1
 * @date 2024-12-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
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
MATRIXnode** MATRIXconvertMatrixToSparse(size_t row, size_t col, Number* a[row]);

/**
 * @brief Prints a representation of a linked list represented
 * sparse array.
 * 
 * @param row number of rows
 * @param a pointer to the array
 */
void MATRIXviewSparse(size_t row, MATRIXnode* a[row]);