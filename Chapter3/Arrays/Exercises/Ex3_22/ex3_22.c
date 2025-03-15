/*
Exercise 3.22

Program 3.8 closest point computation.

This utilises an array of structures. We count the number of pairs of N
randomly generated points in the unit square that can be connected by a
straight line of length < d using the point datatype introduced earlier.
*/

#include <tgmath.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../BuildingBlocks/Examples/Program3_3-4/Point.h"

/**
 * @brief Generates a random
 * double between 0 and 1.
 * 
 * @return double 
 */
double randFloat(void);

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
    srand(time(nullptr));

    size_t N = strtoull(argv[1], NULL, 0);
    double min_dist = INFINITY;
    size_t p1 = 0;
    size_t p2 = 0;

    Point* a = malloc(N*(sizeof(typeof_unqual(*a))));
    for (size_t i = 0; i < N; i++) {
        {a[i].x = randFloat(); a[i].y = randFloat();}
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = i+1; j < N; j++) {
            double d;
            if ((d = POINTdistance(a[i], a[j])) < min_dist) {
                p1 = i;
                p2 = j;
                min_dist = d;
            }
        }
    }
    printf("Closest points are: (%f, %f) and (%f, %f)\n",
        a[p1].x, a[p1].y, a[p2].x, a[p2].y);
}

double randFloat(void) {
    return 1.0*rand() / RAND_MAX;
}