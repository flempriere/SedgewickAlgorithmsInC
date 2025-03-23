/*
Program 3.4

Provides the implementation for the distance function provided in point.h
*/

#include <tgmath.h>
#include "Point.h"

double POINTdistance(Point const p, Point const q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx*dx + dy*dy);
}