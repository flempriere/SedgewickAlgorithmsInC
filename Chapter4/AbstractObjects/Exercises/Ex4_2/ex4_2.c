/**
 * @file ex4_2.c
 * @author Felix Lempriere
 * @brief Test driver code for Item.h implementation of
 * Exercise 4.2
 * @version 0.1
 * @date 2024-12-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdlib.h>
#include <stdio.h> 
#include "point.h"
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
int main(int argc, char* argv[argc]) {

    double a = 1.0;
    double b = a + EPS;
    double c = a - EPS;
    double d = a + 2*TOL;

    point P = {.x = a, .y = a};
    point Q = {.x = a, .y = b};
    point R = {.x = c, .y = b};
    point S = {.x = a, .y = d};

    printf("Testing for equality (%f, %f) and (%f, %f),"
        "result: %s, expected: true\n",
            P.x, P.y, P.x, P.y, eq(P, P) ? "true" : "false");

    printf("Testing for equality (%f, %f) and (%f, %f),"
        "result: %s, expected: true\n",
            P.x, P.y, Q.x, Q.y, eq(P, Q) ? "true" : "false");

    printf("Testing for equality (%f, %f) and (%f, %f),"
        "result: %s, expected: true\n",
            P.x, P.y, R.x, R.y, eq(P, R) ? "true" : "false");

    printf("Testing for equality (%f, %f) and (%f, %f),"
        "result: %s, expected: true\n",
            Q.x, Q.y, R.x, R.y, eq(Q, R) ? "true" : "false");

    printf("Testing for equality (%f, %f) and (%f, %f),"
        "result: %s, expected: false\n",
            P.x, P.y, S.x, S.y, eq(P, S) ? "true" : "false");

    return EXIT_SUCCESS;
}