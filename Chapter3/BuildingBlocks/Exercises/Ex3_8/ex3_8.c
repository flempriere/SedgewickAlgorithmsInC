/*
Exercise 3.8. Extend the point data type to provide a function determining
if three points are collinear to within a tolerance of 10^(-4).
*/

#include <tgmath.h> //for infinity macro
#include "point.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief maximum size of a line.
 * 
 */
#define MAX_LINE 1000

/**
 * @brief number of points to check if collinear
 * 
 */
#define N_POINTS 3

/**
 * @brief Reads in three points from stdin
 * and then reports if they are collinear
 * 
 * @return EXIT_SUCCESS on success, else EXIT_FAILURE
 */
int main(int argc, char* [argc+1]) {

    point points[N_POINTS];

    char line[MAX_LINE];

    for(size_t i = 0; i < N_POINTS && fgets(line, sizeof(line), stdin) != NULL;
        i++) {
        Number x, y;
        if (sscanf(line, "%lf %lf", &x, &y) != 2) {
            printf("Error: must input points as pairs of numbers\n");
            return EXIT_FAILURE;
        }
        points[i] = (point) {.x = x, .y = y};
    }
    printf("The points (%f, %f), (%f, %f) and (%f, %f) are %s collinear\n",
        points[0].x, points[0].y, points[1].x, points[1].y, 
        points[2].x, points[2].y,
        (isCollinear(points[0], points[1], points[2])) ? "" : "not");
    return EXIT_SUCCESS;
}