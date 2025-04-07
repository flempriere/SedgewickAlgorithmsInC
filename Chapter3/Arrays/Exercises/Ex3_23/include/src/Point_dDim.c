/**
 * @file Point_dDim.c
 * @author Felix Lempriere
 * @brief Implementation of the Point_dDim interface.
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "../Point_dDim.h"
#include "MacroLibrary/Generic.h"

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

double POINT_DDIMdistance(Point_DDIM const p, Point_DDIM const q) {
    register double sum = 0.0;
    Dimension const d = MAX(p.dim, q.dim);
    for (register size_t i = 0; i < d; i++)
        sum += pow(POINT_DDIMdxi(p, q, i), 2);
    return sqrt(sum);
}