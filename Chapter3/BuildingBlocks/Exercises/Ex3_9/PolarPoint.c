/*
Exercise 3.9

Implementation for the point interface using a polar coordinate representation
*/

/*
Provides the implementation for the distance function provided in point.h
*/

#include "PolarPoint.h"

#include <tgmath.h>

/**
 * @brief Get the Xcoord of a Polar Point
 *
 * @param p
 * @return double
 */
static inline double POLARPOINTx(PolarPoint const p) {
    return p.r * cos(p.theta);
}

/**
 * @brief Get the Ycoord object of a Polar Point
 *
 * @param p
 * @return double
 */
static inline double POLARPOINTy(PolarPoint const p) {
    return p.r * sin(p.theta);
}

/**
 * @brief Calculates the difference in the x coordinate from p to q.
 *
 * @param p
 * @param q
 * @return double
 */
static inline double POLARPOINTdx(PolarPoint const p, PolarPoint const q) {
    return POLARPOINTx(q) - POLARPOINTx(p);
}

/**
 * @brief Calculates the difference in the y coordinate from p to q.
 *
 * @param p
 * @param q
 * @return double
 */
static inline double POLARPOINTdy(PolarPoint const p, PolarPoint const q) {
    return POLARPOINTy(q) - POLARPOINTy(p);
}

/**
 * @brief Returns the slope of the line from p to q.
 *
 *
 * @param p
 * @param q
 * @return double slope of the line
 * @remark for the case +X/0.0 -> INFINITY, 0.0/0.0 -> NaN, -X/0.0 -> -INFINITY
 */
static inline double POLARPOINTslope(PolarPoint const p, PolarPoint const q) {
    double dy = POLARPOINTdy(p, q);
    double dx = POLARPOINTdx(p, q);
    if (dx) return dy / dx;

    if (fabs(dy) < POLARPOINT_TOLERANCE)    // 0/0 undefined
        return NAN;
    else if (dy > 0)    // use limit
        return INFINITY;
    else    // must be negative.
        return -INFINITY;
}

double POLARPOINTdistance(PolarPoint const p, PolarPoint const q) {
    double const dx = POLARPOINTdx(p, q);
    double const dy = POLARPOINTdy(p, q);
    return sqrt(dx * dx + dy * dy);
}

bool POLARPOINTcollinear(PolarPoint const p, PolarPoint const q,
                         PolarPoint const r) {
    // if two points equal, collinear
    if (POLARPOINTequal(p, q) || POLARPOINTequal(q, r)) { return true; }

    double const m_pq = POLARPOINTslope(p, q);
    double const m_qr = POLARPOINTslope(q, r);

    if (!isfinite(m_pq) && !isfinite(m_qr)) return true;

    return (fabs(m_pq - m_qr) < POLARPOINT_TOLERANCE);
}