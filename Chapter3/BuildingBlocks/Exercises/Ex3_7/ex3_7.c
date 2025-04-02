/*
Exercise 3.7. Write a client program that uses the point data type in
Program 3.3 and Program 3.4 for the following task. Read a sequence of points
(pairs of floating-point numbers from standard input) and find the one that is
closest to the first.
*/

#include "MacroLibrary/Utility.h"
#include "Point/v1/Point.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>    //for infinity macro

/**
 * @brief Maximum size of an input line.
 *
 */
constexpr size_t MAX_LINE = 1000u;

/**
 * @brief Reads in points from standard
 * input and prints out the first point
 * and the closest of the subsequent points.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char * [argc + 1]) {
    register bool first_set = true;
    register Point first = {};
    register Point closest = {};
    register double min_distance = INFINITY;

    char line[MAX_LINE];

    while (fgets(line, sizeof(line), stdin) != nullptr) {
        Number x;
        Number y;
        if (sscanf(line, "%lf %lf", &x, &y) != 2) {
            printf("Error: must input pairs of points\n");
            return EXIT_FAILURE;
        }
        if (first_set) {
            first = CAST(Point){ .x = x, .y = y };
            first_set = false;
        } else {
            register Point candidate = { .x = x, .y = y };
            register double cand_dist = POINTdistance(first, candidate);
            if (cand_dist < min_distance) {
                min_distance = cand_dist;
                closest = candidate;
            }
        }
    }
    printf("First point: (%f, %f)\nClosest point: (%f, %f)\n", first.x, first.y,
           closest.x, closest.y);
    return EXIT_SUCCESS;
}