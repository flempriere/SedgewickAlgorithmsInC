/**
 * @file ex3_21.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3-21.
 *
 * Modify Program 3.8 to utilise an array of structures. We count the number of
 * pairs of N randomly generated points in the unit square that can be connected
 * by a straight line of length < d using the point datatype introduced earlier.
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
 * @brief Fills an array of length n with randomly generated points.
 *
 * @param n length of the array.
 * @param a array of points to fill.
 *
 * @pre The indices [0, n) are valid in the array a.
 * @post a contains randomly generated points in the unit square.
 */
void generate_random_points(size_t const n, Point a[const static n]);

/**
 * @brief Find the closest pair of points in an array @a and store
 * them in @p1 and @p2.
 *
 * @param n length of the array
 * @param a array of points to search.
 * @param p1[out] Pointer containing the first closest point
 * @param p2[out] Pointer containing the Second closest point
 *
 * @pre The indices [0, n) are valid in the array a.
 * @post p1 and p2 contain the closest pair of points in a.
 */
void find_closest_pair(size_t const n, Point const a[const static n],
                       Point p1[const static 1], Point p2[const static 1]);
/**
 * @brief Generates N points in the plane
 * then prints out the closest two.
 *
 * @param argv[1] N
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Error: requires args N\n");
        return EXIT_FAILURE;
    }
    RAND_SEED_TIME;

    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);

    Point* const a = CALLOCEXIT_ON_FAIL(N, *a);
    generate_random_points(N, a);

    Point p1;
    Point p2;
    find_closest_pair(N, a, &p1, &p2);

    printf("Closest points are: (%f, %f) and (%f, %f)\n", p1.x, p1.y, p2.x,
           p2.y);

    free(a);
    return EXIT_SUCCESS;
}

void generate_random_points(size_t const n, Point a[const static n]) {
    for (register size_t i = 0; i < n; i++) {
        a[i] = CAST(Point){ .x = RANDUNIFORM(), .y = RANDUNIFORM() };
    }
}

void find_closest_pair(size_t const n, Point const a[const static n],
                       Point p1[const static 1], Point p2[const static 1]) {
    register double min_dist = INFINITY;
    for (register size_t i = 0; i < n; i++) {
        for (register size_t j = i + 1; j < n; j++) {
            register double d = POINTdistance(a[i], a[j]);
            if (d < min_dist) {
                *p1 = a[i];
                *p2 = a[j];
                min_dist = d;
            }
        }
    }
}