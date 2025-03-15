/*
Provides the implementation for the distance function provided in point.h
*/

#include <tgmath.h>
#include "Point_dDim.h"

double POINT_DDIMdistance(Point_DDIM p, Point_DDIM q, Dimension d) {
    double sum = 0.0;
    for (size_t i = 0; i < d; i++) sum += pow(p.x[i] - q.x[i], 2);
    return sqrt(sum);
}