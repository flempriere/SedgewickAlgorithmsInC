/*
Provides the implementation for the distance function provided in point.h
*/

#include "NumberDouble.h"
#include "Point_v3.h"

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

double POINTdistance(Point const p, Point const q) {
    double const dx = POINTdx(p, q);
    double const dy = POINTdy(p, q);
    return sqrt(dx * dx + dy * dy);
}

double POINTslope(Point const p, Point const q) {
    return POINTdy(p, q) / POINTdx(p, q);
}

bool POLARPOINTis_collinear(Point const p, Point const q, Point const r) {
    /*if two of the points are the same then
    always colinear with third */
    if (POINTis_equal(p, q) || POINTis_equal(q, r)) { return true; }

    double const m_pq = (q.y - p.y) / (q.x - p.x);
    double const m_qr = (r.y - q.y) / (r.x - q.x);
    return (fabs(m_pq - m_qr) < POINTTOLERANCE);
}

Point POINTrandom(void) {
    return (Point) { .x = NUMBERrandom(), .y = NUMBERrandom() };
}
