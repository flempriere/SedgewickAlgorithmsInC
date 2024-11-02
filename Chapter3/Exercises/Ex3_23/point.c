/*
Provides the implementation for the distance function provided in point.h
*/

#include <tgmath.h>
#include "point.h"
#include <stdio.h>

double distance(point p, point q, Dimension d) {
    double sum = 0.0;
    for (size_t i = 0; i < d; i++) sum += pow(p.x[i] - q.x[i], 2);
    return sqrt(sum);
}