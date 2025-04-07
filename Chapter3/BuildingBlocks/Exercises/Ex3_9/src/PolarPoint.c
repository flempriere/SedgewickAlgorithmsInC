/**
 * @file PolarPoint.c
 * @author Felix Lempriere
 * @brief Implementation of the PolarPoint interface.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "../PolarPoint.h"

#include <tgmath.h>

/**
 * @brief Get the Xcoord of a Polar Point
 *
 * @param p
 * @return double
 */
static inline double POLARPOINTx(PolarPoint const POLARPOINTp) {
    return POLARPOINTp.r * cos(POLARPOINTp.theta);
}

/**
 * @brief Get the Ycoord object of a Polar Point
 *
 * @param p
 * @return double
 */
static inline double POLARPOINTy(PolarPoint const POLARPOINTp) {
    return POLARPOINTp.r * sin(POLARPOINTp.theta);
}

/**
 * @brief Calculates the difference in the x coordinate from p to q.
 *
 * @param p
 * @param q
 * @return double
 */
static inline double POLARPOINTdx(PolarPoint const POLARPOINTp,
                                  PolarPoint const POLARPOINTq) {
    return POLARPOINTx(POLARPOINTq) - POLARPOINTx(POLARPOINTp);
}

/**
 * @brief Calculates the difference in the y coordinate from p to q.
 *
 * @param p
 * @param q
 * @return double
 */
static inline double POLARPOINTdy(PolarPoint const POLARPOINTp,
                                  PolarPoint const POLARPOINTq) {
    return POLARPOINTy(POLARPOINTq) - POLARPOINTy(POLARPOINTp);
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
static inline double POLARPOINTslope(PolarPoint const POLARPOINTp,
                                     PolarPoint const POLARPOINTq) {
    double dy = POLARPOINTdy(POLARPOINTp, POLARPOINTq);
    double dx = POLARPOINTdx(POLARPOINTp, POLARPOINTq);
    if (dx) return dy / dx;

    if (fabs(dy) < POLARPOINTTOLERANCE)    // 0/0 undefined
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

    return (fabs(m_pq - m_qr) < POLARPOINTTOLERANCE);
}