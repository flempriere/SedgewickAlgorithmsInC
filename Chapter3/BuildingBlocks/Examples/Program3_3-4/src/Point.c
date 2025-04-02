/*
Program 3.4

Provides the implementation for the distance function provided in point.h
*/

#include "../Point.h"

#include <tgmath.h>

/**
 * @brief Calculates the difference in the x coordinate from p to q.
 *
 * @param p
 * @param q
 * @return double
 */
static inline double POINTdx(Point const p, Point const q) { return q.x - p.x; }

/**
 * @brief Calculates the difference in the y coordinate from p to q.
 *
 * @param p
 * @param q
 * @return double
 */
static inline double POINTdy(Point const p, Point const q) { return q.y - p.y; }

double POINTdistance(Point const p, Point const q) {
    double dx = POINTdx(p, q);
    double dy = POINTdy(p, q);
    return sqrt(dx * dx + dy * dy);
}