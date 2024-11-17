/*
Exercise 3.10: Define a datatype for triangles in the unit square, including
a function that computes the area of a triangle. Then write a client program
that generates random triples of pairs of floats between 0 and 1 and computes
empircally the average area of the triangles generated.

*/

#include <tgmath.h>
#include <stdlib.h>
#include <stdio.h>
#include "ex3_10.h"


/**
 * @brief Number of N values to test over.
 * 
 */
#define N_CASES 5

/**
 * @brief Initial value of N for test cases
 * 
 */
#define N_INIT 10

/**
 * @brief Generates a random triangle and
 * stores its values in t.
 * 
 * @param t A triangle to be randomised
 */
void randTriangle(triangle* t);

/**
 * @brief Generates a random point and
 * stores its value in p
 * 
 * @param p A point to be randomised
 */
void randPoint(point* p);

/**
 * @brief For N = N_INIT, 10(N_INIT), 100(N_INIT)
 * Generates N random triangles, calculates their
 * area, and determines the avg and std.dev statistics.
 * 
 */
int main(int argc, char* argv[argc + 1]) {

    size_t N = N_INIT;

    triangle t;
    for (size_t j = 0; j < N_CASES; N *= 10, j++) {

        double m1 = 0.0;
        double m2 = 0.0;

        for (size_t i = 0; i < N; i++) {
            randTriangle(&t);
            double triangle_area = area(t); 
            m1 += ((double) triangle_area)/N;
            m2 += ((double) triangle_area*triangle_area) / N; 
        }
        printf("Running using N: %zu\n", N);
        printf("       Average: %f\n", m1);
        printf("Std. deviation: %f\n", sqrt(m2 - m1*m1));
    }
    return EXIT_SUCCESS;
}

void randTriangle(triangle* t) {
    randPoint(&(t->a));
    randPoint(&(t->b));
    randPoint(&(t->c));
}

void randPoint(point* p) {
    p->x = randNum();
    p->y = randNum();
}

