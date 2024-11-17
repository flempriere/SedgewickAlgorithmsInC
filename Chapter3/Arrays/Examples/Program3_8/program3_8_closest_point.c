/*
Program 3.8 closest point computation.

This utilises an array of structures. We count the number of pairs of N
randomly generated points in the unit square that can be connected by a
straight line of length < d using the point datatype introduced earlier.
*/

#include <tgmath.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"

/**
 * @brief Generates a random double between
 * 0 and 1.
 * 
 * @return double 
 */
double randFloat(void);

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
    
    double d = atof(argv[2]);
    size_t N = strtoull(argv[1], NULL, 0);

    point* a = malloc(N*(sizeof(typeof_unqual(*a))));
    for (size_t i = 0; i < N; i++) {
        {a[i].x = randFloat(); a[i].y = randFloat();}
    }

    size_t cnt = 0;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = i+1; j < N; j++) {
            if (distance(a[i], a[j]) < d) cnt++;
        }
    }
    printf("%zu edges shorter than %f\n", cnt, d);
    return EXIT_SUCCESS;
}

double randFloat(void) {
    return 1.0*rand() / RAND_MAX;
}