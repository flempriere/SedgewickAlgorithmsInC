/*
Provides the implementation for the distance function provided in point.h
*/

#include "../Point_v3.h"

#include "Number/v1/NumberDouble/NumberDouble.h"

#include <tgmath.h>

/**
 * @brief Return the dX from p to q.
 *
 * @param p
 * @param q
 @ return double >= 0
 */
static inline double POINTdx(Point const p, Point const q) { return q.x - p.x; }

/**
 * @brief Return the dY from p to q
 *
 * @param p
 * @param q
 * @return double
 */
static inline double POINTdy(Point const p, Point const q) { return q.y - p.y; }

/**
 * @brief Returns the slope of the line from p to q.
 *
 *
 * @param p
 * @param q
 * @return double slope of the line
 * @remark for the case +X/0.0 -> INFINITY, 0.0/0.0 -> NaN, -X/0.0 -> -INFINITY
 */
static inline double POINTslope(Point const p, Point const q) {
    double dy = POINTdy(p, q);
    double dx = POINTdx(p, q);
    if (dx) return dy / dx;

    if (fabs(dy) < POINTTOLERANCE)    // 0/0 undefined
        return NAN;
    else if (dy > 0)    // use limit
        return INFINITY;
    else    // must be negative.
        return -INFINITY;
}

double POINTdistance(Point const p, Point const q) {
    double const dx = POINTdx(p, q);
    double const dy = POINTdy(p, q);
    return sqrt(dx * dx + dy * dy);
}

bool POLARPOINTcollinear(Point const p, Point const q, Point const r) {
    /*if two of the points are the same then
always colinear with third */
    if (POINTequal(p, q) || POINTequal(q, r)) { return true; }

    double m_pq = POINTslope(p, q);
    double m_qr = POINTslope(q, r);

    if (!isfinite(m_pq) && !isfinite(m_qr))
        return true;    // both slopes infinite

    return (fabs(m_pq - m_qr) < POINTTOLERANCE);
}

Point POINTrandom(void) {
    return (Point) { .x = NUMBERrandom(), .y = NUMBERrandom() };
}
