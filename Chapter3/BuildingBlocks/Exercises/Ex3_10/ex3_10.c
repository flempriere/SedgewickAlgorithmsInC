/*
Exercise 3.10: Define a datatype for triangles in the unit square, including
a function that computes the area of a triangle. Then write a client program
that generates random triples of pairs of floats between 0 and 1 and computes
empircally the average area of the triangles generated.

*/

#include <tgmath.h>
#include <stdlib.h>
#include <stdio.h>
#include "ex3_10.h"\

#define N_CASES 3
#define N_INIT 10

void randTriangle(triangle* t);
void randPoint(point* p);

int main(int argc, char* argv[argc + 1]) {

    size_t N = N_INIT;

    triangle t;
    for (size_t j = 0; j <= N_CASES; N *= 10, j++) {

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
    return 0;
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

