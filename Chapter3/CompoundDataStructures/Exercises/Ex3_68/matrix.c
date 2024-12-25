/**
 * @file matrix.c
 * @author Felix Lempriere
 * @brief Implementation file for matrix.h
 * @version 0.1
 * @date 2024-12-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "matrix.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10
#define GEN_NUM rand() % MAX_NUM

#define COIN_TOSS ((double) rand() / (double) RAND_MAX)

Number** malloc2d(size_t row, size_t col) {
    Number** a = malloc(row * sizeof(typeof(*a)));
    while(--row < SIZE_MAX) a[row] = malloc(col * sizeof(typeof(**a)));
    return a;
}

void viewArray(size_t row, size_t col, Number* a[row]) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            printf("%d ",  a[i][j]);
        }
        printf("\n");
    }
}

Number** generateRandomSparse(size_t row, size_t col,  double p_zero) {
    if (0 > p_zero || p_zero > 1.0) {
        return nullptr;
    }
    Number** a = malloc2d(row, col);
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            a[i][j] = (COIN_TOSS > p_zero) ? GEN_NUM : 0;
        }
    }
    return a;
}

/**
 * @brief Insert a new matrix element containing
 * value @v and column index @col pointing to nxt
 * 
 * @param v 
 * @param col 
 * @param nxt 
 * @return node* the new node
 */
static node* NEW(Number v, size_t col,  node* nxt) {
    node* x = malloc(sizeof(typeof(*x)));
    x->val = v;
    x->col = col;
    x->next = nxt;
    return x;
}
/**
 * @brief Create and insert a new matrix element into
 * the row list @target with value @v and column index
 * @col. The new element is inserted into the list using
 * an insertion sort to maintain a non-decreasing column index.
 * 
 * @param v
 * @param col 
 * @param target 
 * @return node* pointing to the head of the row list
 */
static node* insertNEW(Number v, size_t col, node* target) {
    //insert at head of list
    if (!target || target->col > col) return NEW(v, col, target);
    //iterate until end of list or found greater element
    node* cur = target;
    for (; cur->next && cur->next->col < col; cur=cur->next);
    node* new = NEW(v, col, cur->next);
    cur->next = new;
    return target;
}

sparseMatrix* convertMatrixToSparse(size_t row, size_t col, Number* a[row]) {
    sparseMatrix* m = malloc(sizeof(typeof(*m)));
    node** l = malloc(row * sizeof(typeof(*l)));
    for (size_t i = 0; i < row; i++) l[i] = nullptr;

    for (size_t i = 0; i < row; i++) {
        for (size_t j = (col - 1); j < col; j--) {
            if (a[i][j]) l[i] = NEW(a[i][j], j, l[i]);         
        }
    }
    m->row = row;
    m->col = col;
    m->m = l;
    return m;
}

void viewSparse(sparseMatrix* m) {
    for (size_t i = 0; i < m->row; i++) {
        printf("row index %zu: ", i);
        for (node* cur = m->m[i]; cur != nullptr; cur = cur->next) {
            printf("(col: %zu, val: %d)%s", cur->col, cur->val,
                (cur->next) ? ", " : ""); 
        }
        printf("\n");
    }
}

sparseMatrix* sparseMatMul(sparseMatrix* m1, sparseMatrix* m2) {
    if (m1->col != m2->row) {
        fprintf(stderr, "Error: incompatible matrices,"
            "check the rows and columns\n");
        return nullptr;
    }
    sparseMatrix* product = malloc(sizeof(typeof(*product)));

    product->row = m1->row;
    product->col = m2->col;
    node** l = malloc(m1->row * sizeof(typeof(*l)));
    product->m = l;

    for (size_t i = 0; i < m1->row; i++) {
        for (size_t j = 0; j < m2->col; j++) {
            Number val = 0;
            for (size_t k = 0; k < m1->col; k++) {
                //find m2_{kj}
                node* curM2 = nullptr;
                for (curM2 = m2->m[k]; curM2 && curM2->col != j; 
                    curM2=curM2->next);
                if (!curM2) continue; //nullptr found

                //find m1_{ik}
                node* curM1 = nullptr;
                for (curM1 = m1->m[i]; curM1 && curM1->col != k;
                    curM1 = curM1->next);
                if (!curM1) continue; //nullptr found
                val += (curM1->val * curM2->val);
            }
            if (val) product->m[i] = insertNEW(val, j, product->m[i]);
        }
    }
    return product; 
}