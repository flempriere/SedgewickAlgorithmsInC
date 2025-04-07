/**
 * @file ex3_23.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3-23.
 *
 * Modify Program 3.8 to work with a d-dimensional point implementation.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/DefaultCalloc.h"
#include "MacroLibrary/Generic.h"
#include "MacroLibrary/NumberParse.h"
#include "MacroLibrary/Random.h"
#include "include/Point_dDim.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Fill an array @a of @dim dimensional points with @n randomly
 * generated points.
 *
 * @param dim dimension of the points.
 * @param n length of the array.
 * @param a array of points to fill.
 */
void generate_random_points(Dimension const dim, size_t const n,
                            Point_DDIM a[const static n]);

/**
 * @brief Count the number of edges between @dim dimensional points in the
 * array @a of length less than @d.
 *
 * @param d Maximum length of an edge.
 * @param n length of the array.
 * @param a array of points to search.
 *
 * @pre The indices [0, n) are valid in the array a.
 * @post count is the number of edges in a with length less than d.
 * @return size_t The number of edges in a with length less than d.
 */
size_t count_close_pairs(double const d, size_t const n,
                         Point_DDIM const a[const static n]);
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

    register Dimension const dim = getDim(argv[1]);
    register size_t const N = NUMPARSEexit_on_fail(N, argv[2]);
    register double const d = NUMPARSEexit_on_fail(d, argv[3]);

    Point_DDIM* const a = CALLOCEXIT_ON_FAIL(N, *a);
    generate_random_points(dim, N, a);
    register size_t count = count_close_pairs(d, N, a);
    printf("%zu edges shorter than %f\n", count, d);

    free(a);
    return EXIT_SUCCESS;
}

Dimension getDim(char s[static 1]) {
    register Dimension dim = NUMPARSEexit_on_fail(dim, s);
    return MIN(dim, POINT_DDIMMAX_DIM);
}

void generate_random_points(Dimension dim, size_t const n, Point_DDIM a[n]) {
    for (register size_t i = 0; i < n; i++) {
        a[i].dim = dim;
        for (register Dimension idx = 0; idx < dim; idx++) {
            a[i].x[idx] = RANDUNIFORM();
        }
    }
}

size_t count_close_pairs(double const d, size_t const n,
                         Point_DDIM const a[n]) {
    register size_t count = 0;
    for (register size_t i = 0; i < n; i++) {
        for (register size_t j = i + 1; j < n; j++) {
            if (POINT_DDIMdistance(a[i], a[j]) < d) { count++; }
        }
    }
    return count;
}