/*
Provides the implementation for the distance function provided in point.h
*/

#include "Point_dDim.h"

#include <tgmath.h>

double POINT_DDIMdistance(Point_DDIM const p, Point_DDIM const q,
                          Dimension const d) {
    register double sum = 0.0;
    for (register size_t i = 0; i < d; i++) sum += pow(p.x[i] - q.x[i], 2);
    return sqrt(sum);
}