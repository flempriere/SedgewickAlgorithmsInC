/*
Program 3.8 closest point computation.

This utilises an array of structures. We count the number of pairs of N
randomly generated points in the unit square that can be connected by a
straight line of length < d using the point datatype introduced earlier.
*/

#include "MacroLibrary/DefaultCalloc.h"
#include "MacroLibrary/NumberParse.h"
#include "MacroLibrary/Random.h"
#include "Point/v1/Point.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Fills an array @a of length n with randomly generated points.
 *
 * @param n
 * @param a
 */
void generate_random_points(size_t const n, Point a[n]);

/**
 * @brief Counts the number of edges between points in the array @a
 * of length less than @d.
 *
 * @param d
 * @param n
 * @param a
 * @return size_t
 */
size_t count_close_pairs(double const d, size_t const n, Point const a[n]);
/**
 * @brief Generates N random points
 * and counts how many can be connected with
 * a straight line of length less than d.
 *
 * @param argv[1] N
 * @param argv[2] d
 * @return EXIT_SUCCESS if successful else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Error: requires args N d\n");
        return EXIT_FAILURE;
    }

    RAND_SEED_TIME;

    register double const d = NUMPARSEexit_on_fail(d, argv[2]);
    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);

    register Point* const a = CALLOC_FAILS_EXIT(N, *a);

    generate_random_points(N, a);
    size_t cnt = count_close_pairs(d, N, a);

    printf("%zu edges shorter than %f\n", cnt, d);
    free(a);
    return EXIT_SUCCESS;
}

void generate_random_points(size_t const n, Point a[n]) {
    for (register size_t i = 0; i < n; i++) {
        a[i] = CAST(Point){ .x = RANDUNIFORM(), .y = RANDUNIFORM() };
    }
}

size_t count_close_pairs(double const d, size_t const n, Point const a[n]) {
    register size_t cnt = 0;
    for (register size_t i = 0; i < n; i++) {
        for (register size_t j = i + 1; j < n; j++) {
            if (POINTdistance(a[i], a[j]) < d) cnt++;
        }
    }
    return cnt;
}