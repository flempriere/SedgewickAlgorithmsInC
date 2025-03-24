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
static inline double POLARPOINTxcoordinate(PolarPoint const p) {
    return p.r * cos(p.theta);
}

/**
 * @brief Get the Ycoord object of a Polar Point
 *
 * @param p
 * @return double
 */
static inline double POLARPOINTycoordinate(PolarPoint const p) {
    return p.r * sin(p.theta);
}

double POLARPOINTdistance(PolarPoint const p, PolarPoint const q) {
    double const dx = POLARPOINTxcoordinate(p) - POLARPOINTxcoordinate(q);
    double const dy = POLARPOINTycoordinate(p) - POLARPOINTycoordinate(q);
    return sqrt(dx * dx + dy * dy);
}

bool POLARPOINTis_collinear(PolarPoint const p, PolarPoint const q,
                            PolarPoint const r) {
    // if two points equal, collinear
    if (POLARPOINTis_equal(p, q) || POLARPOINTis_equal(q, r)) { return true; }
    double const m_pq = (POLARPOINTycoordinate(q) - POLARPOINTycoordinate(p)) /
                        (POLARPOINTxcoordinate(q) - POLARPOINTxcoordinate(p));
    double const m_qr = (POLARPOINTycoordinate(q) - POLARPOINTycoordinate(r)) /
                        (POLARPOINTxcoordinate(q) - POLARPOINTxcoordinate(r));
    return (fabs(m_pq - m_qr) < POLARPOINTTOLERANCE);
}