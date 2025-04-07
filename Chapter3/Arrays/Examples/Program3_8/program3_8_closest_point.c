/**
 * @file program3_8_closest_point.c
 * @author Felix Lempriere
 * @brief Program 3.8: Closest Point Calculation.
 *
 * Program 3.8 closest point computation.
 * This utilises an array of structures. We count the number of pairs of N
 * randomly generated points in the unit square that can be connected by a
 * straight line of length < d using the point datatype introduced earlier.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/DefaultCalloc.h"
#include "MacroLibrary/NumberParse.h"
#include "MacroLibrary/Random.h"
#include "Point/v1/Point.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Fills an array a of length n with randomly generated points in the
 * unit square.
 *
 * @param n size of the array > 0.
 * @param a pointer to the array.
 *
 * @pre The indices [0, n) are valid in the array a.
 * @post The array a is filled with random points.
 */
void generate_random_points(size_t const n, Point a[const static n]);

/**
 * @brief Counts the number of edges between points in the array @a
 * of length less than @d.
 *
 * @param d length of the edge.
 * @param n length of the array.
 * @param a pointer to the array.
 *
 * @pre d > 0
 * @pre n > 0
 * @pre The indices [0, n) are valid in the array a.
 * 
 * @return size_t The number of edges shorter than d.
 */
size_t count_close_pairs(double const d, size_t const n, Point const a[const static n]);
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

    register Point* const a = CALLOCEXIT_ON_FAIL(N, *a);

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