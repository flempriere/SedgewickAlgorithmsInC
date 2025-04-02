/*
Provides the implementation for the distance function provided in point.h
*/

#include "../Point_dDim.h"

#include <tgmath.h>

/**
 * @brief Calculate the difference from p to q along the i-th dimension
 *
 * @param p
 * @param q
 * @param i
 * @return double
 */
static inline double POINT_DDIMdxi(Point_DDIM const p, Point_DDIM const q,
                                   Dimension const i) {
    return q.x[i] - p.x[i];
}

double POINT_DDIMdistance(Point_DDIM const p, Point_DDIM const q,
                          Dimension const d) {
    register double sum = 0.0;
    for (register size_t i = 0; i < d; i++)
        sum += pow(POINT_DDIMdxi(p, q, i), 2);
    return sqrt(sum);
}