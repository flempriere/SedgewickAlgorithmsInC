/**
 * @file ex4_1.c
 * @author Felix Lempriere
 * @brief Test driver code for Item.h implementation of
 * Exercise 4.1
 * @version 0.1
 * @date 2024-12-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdlib.h>
#include <stdio.h> 
#include "Item.h"


/**
 * @brief numerical offset for testing equality
 * 
 */
#define EPS 0.5 * TOL;


/**
 * @brief Test eq(A,B) implementation in Item.h
 * by testing equality on the same number, a number
 * a and b with b = a + 0.5*TOL, a number a and c
 * with c = a - 0.5*TOL, and a number a and d such that
 * d = a + 2*TOL.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(void) {

    double a = 1.0;
    double b = a + EPS;
    double c = a - EPS;
    double d = a + 2*TOL;

    printf("Testing eq(%f, %f)\nResult: %s, Expected: true\n",
        a, a, ITEMeq(a,a) ? "true" : "false");
    
    printf("Testing eq(%f, %f)\nResult: %s, Expected: true\n",
        a, b, ITEMeq(a,b) ? "true" : "false");

    printf("Testing eq(%f, %f)\nResult: %s, Expected: true\n",
        a, c, ITEMeq(a,c) ? "true" : "false");
    
    printf("Testing eq(%f, %f)\nResult: %s, Expected: false\n",
        a, d, ITEMeq(a,d) ? "true" : "false");

    printf("Testing eq(0, 0)\nResult: %s, Expected: true\n",
        ITEMeq(0,0) ? "true" : "false");

    return EXIT_SUCCESS;
}