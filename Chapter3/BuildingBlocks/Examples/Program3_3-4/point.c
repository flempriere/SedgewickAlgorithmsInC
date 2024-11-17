/*
Program 3.4

Provides the implementation for the distance function provided in point.h
*/

#include <tgmath.h>
#include "point.h"

double distance(point p, point q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx*dx + dy*dy);
}