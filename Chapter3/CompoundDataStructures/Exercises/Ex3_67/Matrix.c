/**
 * @file matrix.c
 * @author Felix Lempriere
 * @brief Implementation file for matrix.h
 * @version 0.1
 * @date 2024-12-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Matrix.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10
#define GEN_NUM rand() % MAX_NUM

#define COIN_TOSS ((double) rand() / (double) RAND_MAX)

Number** MATRIXinit(size_t row, size_t col) {
    Number** a = malloc(row * sizeof(typeof(*a)));
    while(--row < SIZE_MAX) a[row] = malloc(col * sizeof(typeof(**a)));
    return a;
}

void MATRIXview(size_t row, size_t col, Number* a[row]) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            printf("%d ",  a[i][j]);
        }
        printf("\n");
    }
}

Number** MATRIXgenerateRandomSparse(size_t row, size_t col,  double p_zero) {
    if (0 > p_zero || p_zero > 1.0) {
        return nullptr;
    }
    Number** a = MATRIXinit(row, col);
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            a[i][j] = (COIN_TOSS > p_zero) ? GEN_NUM : 0;
        }
    }
    return a;
}

MATRIXnode* NEW(Number v, size_t col,  MATRIXnode* nxt) {
    MATRIXnode* x = malloc(sizeof(typeof(*x)));
    x->val = v;
    x->col = col;
    x->next = nxt;
    return x;
}

MATRIXnode** MATRIXconvertMatrixToSparse(size_t row, size_t col, Number* a[row]) {
    MATRIXnode** l = malloc(row * sizeof(typeof(*l)));
    for (size_t i = 0; i < row; i++) l[i] = nullptr;

    for (size_t i = 0; i < row; i++) {
        for (size_t j = (col - 1); j < col; j--) {
            if (a[i][j]) l[i] = NEW(a[i][j], j, l[i]);         
        }
    }
    return l;
}

void MATRIXviewSparse(size_t row, MATRIXnode* a[row]) {
    for (size_t i = 0; i < row; i++) {
        printf("row index %zu: ", i);
        for (MATRIXnode* cur = a[i]; cur != nullptr; cur = cur->next) {
            printf("(col: %zu, val: %d)%s", cur->col, cur->val,
                (cur->next) ? ", " : ""); 
        }
        printf("\n");
    }
}