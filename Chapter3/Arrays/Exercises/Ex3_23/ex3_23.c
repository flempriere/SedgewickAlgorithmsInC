/*
Exercise 3.23

Modify Program 3.8 to work for a d-dimensional point.
*/

#include "../../../../MacroLibrary/DefaultCalloc.h"
#include "../../../../MacroLibrary/Generic.h"
#include "../../../../MacroLibrary/NumberParse.h"
#include "../../../../MacroLibrary/Random.h"
#include "src/Point_dDim.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Extract dimension from an input string.
 *
 * @param s string to extract dim from.
 * @return Dimension
 */
Dimension getDim(char s[static 1]);

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

    Dimension const dim = getDim(argv[1]);
    size_t const N = NUMPARSEexit_on_fail(N, argv[2]);
    double const d = NUMPARSEexit_on_fail(d, argv[3]);

    Point_DDIM* const a = DEFAULTCallocNVAR(N, *a);
    if (!a) {
        fprintf(stderr, "Failed to allocate Point array\n");
        return EXIT_FAILURE;
    }

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

Dimension getDim(char s[static 1]) {
    Dimension dim = NUMPARSEexit_on_fail(dim, s);
    return MIN(dim, POINT_DDIM_MAX_DIM);
}