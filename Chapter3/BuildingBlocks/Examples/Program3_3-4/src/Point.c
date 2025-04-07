/**
 * @file Point.c
 * @author Felix Lempriere
 * @brief Program 3.4: Implementation of the Point type.
 *
 * This file provides an implementation of the Point interface defined in
 * (Program 3.3)[../Point.h]
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
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
static inline double POINTdx(Point const POINTp, Point const POINTq) {
    return POINTq.x - POINTp.x;
}

/**
 * @brief Calculates the difference in the y coordinate from p to q.
 *
 * @param p
 * @param q
 * @return double
 */
static inline double POINTdy(Point const POINTp, Point const POINTq) {
    return POINTq.y - POINTp.y;
}

double POINTdistance(Point const p, Point const q) {
    double dx = POINTdx(p, q);
    double dy = POINTdy(p, q);
    return sqrt(dx * dx + dy * dy);
}