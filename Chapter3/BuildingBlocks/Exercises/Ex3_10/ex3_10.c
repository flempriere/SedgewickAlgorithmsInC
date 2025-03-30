/*
Exercise 3.10: Define a datatype for triangles in the unit square, including
a function that computes the area of a triangle. Then write a client program
that generates random triples of pairs of floats between 0 and 1 and computes
empircally the average area of the triangles generated.

*/

#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Utility.h"
#include "src/Triangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Number of N values to test over.
 *
 */
constexpr size_t N_CASES = 5u;

/**
 * @brief Initial value of N for test cases
 *
 */
constexpr size_t N_INIT = 10u;

/**
 * @brief For N = N_INIT, 10(N_INIT), 100(N_INIT)
 * Generates N random triangles, calculates their
 * area, and determines the avg and std.dev statistics.
 *
 */
int main(int argc, char* argv[argc + 1]) {
    register size_t N = N_INIT;

    RAND_SEED_TIME;

    for (register size_t j = 0; j < N_CASES; N *= 10, j++) {
        register double m1 = 0.0;
        register double m2 = 0.0;

        for (register size_t i = 0; i < N; i++) {
            register Triangle t = TRIANGLErandom();
            register double triangle_area = TRIANGLEarea(t);
            m1 += (triangle_area) / CAST(double) N;
            m2 += (triangle_area * triangle_area) / CAST(double) N;
        }

        printf("Running using N: %zu\n", N);
        printf("        Average: %f\n", m1);
        printf(" Std. deviation: %f\n", sqrt(m2 - m1 * m1));
    }

    return EXIT_SUCCESS;
}
