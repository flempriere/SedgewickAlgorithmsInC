/*
Exercise 3.7. Write a client program that uses the point data type in
Program 3.3 and Program 3.4 for the following task. Read a sequence of points
(pairs of floating-point numbers from standard input) and find the one that is
closest to the first.
*/

#include <tgmath.h> //for infinity macro
#include "point.h"
#include <stdio.h>

#define MAX_LINE 1000

int main(int argc, char* [argc+1]) {

    bool first_set = true;
    point first = {};
    point closest = {};
    double min_distance = INFINITY;

    char line[MAX_LINE];

    while(fgets(line, sizeof(line), stdin) != NULL) {
        Number x, y;
        if (sscanf(line, "%lf %lf", &x, &y) != 2) {
            printf("Error: must input pairs of points\n");
            return 1;
        }
        switch(first_set) {
            case true:
                first.x = x;
                first.y = y;
                first_set = false;
                break;
            case false:
                point candidate = {.x = x, .y = y};
                double cand_dist;
                if ((cand_dist = distance(first, candidate)) < min_distance) {
                    min_distance = cand_dist;
                    closest.x = candidate.x;
                    closest.y = candidate.y;
                }
                //print after every point for debugging
                printf("First point: (%f, %f)\nClosest point: (%f, %f)\n",
                    first.x, first.y, closest.x, closest.y);
                break;
        }

    }
    return 0;
}