/*
Exercise 3.22

Program 3.8 closest point computation.

This utilises an array of structures. We count the number of pairs of N
randomly generated points in the unit square that can be connected by a
straight line of length < d using the point datatype introduced earlier.
*/

#include "../../../../MacroLibrary/Random.h"
#include "../../../BuildingBlocks/Examples/Program3_3-4/Point.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <time.h>

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

    register size_t const N = strtoull(argv[1], NULL, 0);
    register double min_dist = INFINITY;
    register size_t p1 = 0;
    register size_t p2 = 0;

    Point* a = malloc(N * (sizeof(typeof_unqual(*a))));
    for (register size_t i = 0; i < N; i++) {
        {
            a[i].x = RAND_UNIFORM();
            a[i].y = RAND_UNIFORM();
        }
    }

    for (register size_t i = 0; i < N; i++) {
        for (register size_t j = i + 1; j < N; j++) {
            register double d;
            if ((d = POINTdistance(a[i], a[j])) < min_dist) {
                p1 = i;
                p2 = j;
                min_dist = d;
            }
        }
    }
    printf("Closest points are: (%f, %f) and (%f, %f)\n", a[p1].x, a[p1].y,
           a[p2].x, a[p2].y);
}