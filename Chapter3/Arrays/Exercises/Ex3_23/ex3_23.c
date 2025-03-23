/*
Exercise 3.23

Modify Program 3.8 to work for a d-dimensional point.
*/

#include "../../../../MacroLibrary/Random.h"
#include "Point_dDim.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <time.h>

/**
 * @brief Generates N points in d
 * dimensions and counts the number that
 * can be connected by a line segment of
 * length less than d
 *
 * @param argv[1] dim, dimensions of points
 * @param argv[2] N, number of points to generate
 * @param argv[3] d, distance to check points
 * @return EXIT_SUCCESS on successful completion else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 4) {
        fprintf(stderr, "Error: requires args dim, N, d\n");
        return EXIT_FAILURE;
    }

    Dimension dim = strtoull(argv[1], NULL, 0);
    dim = (dim < POINT_DDIM_MAX_DIM) ? dim : POINT_DDIM_MAX_DIM;
    size_t const N = strtoull(argv[2], NULL, 0);
    double d = atof(argv[3]);

    Point_DDIM* a = malloc(N * (sizeof(typeof_unqual(*a))));

    for (register size_t i = 0; i < N; i++) {
        for (register Dimension idx = 0; idx < dim; idx++) {
            a[i].x[idx] = RAND_UNIFORM();
        }
    }

    register size_t count = 0;
    for (register size_t i = 0; i < N; i++) {
        for (register size_t j = i + 1; j < N; j++) {
            if (POINT_DDIMdistance(a[i], a[j], dim) < d) { count++; }
        }
    }
    printf("%zu edges shorter than %f\n", count, d);

    return EXIT_SUCCESS;
}