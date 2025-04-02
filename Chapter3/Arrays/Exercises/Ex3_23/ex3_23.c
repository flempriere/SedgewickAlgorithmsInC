/*
Exercise 3.23

Modify Program 3.8 to work for a d-dimensional point.
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
 * @param dim 
 * @param n 
 * @param a 
 */
void generate_random_points(Dimension dim, size_t const n, Point_DDIM a[n]);

/**
 * @brief Count the number of edges between @dim dimensional points in the
 * array @a of length less than @d. 
 * 
 * @param d 
 * @param dim 
 * @param n 
 * @param a 
 * @return size_t 
 */
size_t count_close_pairs(double const d, Dimension dim, size_t const n, Point_DDIM const a[n]);
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

    Point_DDIM* const a = CALLOC_FAILS_EXIT(N, *a);
    generate_random_points(dim, N, a);
    register size_t count = count_close_pairs(d, dim, N, a);
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
        for (register Dimension idx = 0; idx < dim; idx++) {
            a[i].x[idx] = RANDUNIFORM();
        }
    }
}

size_t count_close_pairs(double const d, Dimension dim, size_t const n, Point_DDIM const a[n]) {
    register size_t count = 0;
    for (register size_t i = 0; i < n; i++) {
        for (register size_t j = i + 1; j < n; j++) {
            if (POINT_DDIMdistance(a[i], a[j], dim) < d) { count++; }
        }
    }
    return count;
}