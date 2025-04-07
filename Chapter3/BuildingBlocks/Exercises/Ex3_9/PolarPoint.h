/**
 * @file PolarPoint.h
 * @author Felix Lempriere
 * @brief Variant of the Point.h interface utilising polar coordinates as
 * the underlying representation.
 *
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */
#pragma once

/**
 * @brief Numerical tolerance for
 * collinear calculation.
 *
 */
constexpr double POLARPOINTTOLERANCE = 10e-4;

/**
 * @brief Localises numerical data definition
 *
 */
typedef double Number;

/**
 * @brief Two-dimensional Point data type
 * consisting of an r and theta coordinate.
 *
 */
typedef struct {
    Number r;
    Number theta;
} PolarPoint;

/**
 * @brief Calculates the euclidean distance
 * between two points.
 *
 * @param p point
 * @param q point
 * @return double
 */
double POLARPOINTdistance(PolarPoint const p, PolarPoint const q);

/**
 * @brief Determine if two points p and q are equal to a given
 * tolerance.
 *
 * @param p
 * @param q
 * @return true
 * @return false
 */
static inline bool POLARPOINTequal(PolarPoint const POLARPOINTp,
                                   PolarPoint const POLARPOINTq) {
    return POLARPOINTdistance(POLARPOINTp, POLARPOINTq) < POLARPOINTTOLERANCE;
}

/**
 * @brief Determines if three points are collinear
 * to within a tolerance factor.
 *
 * @param p point
 * @param q point
 * @param r point
 * @return true if collinear else
 * @return false
 *
 * @see POLARPOINTTOLERANCE
 */
bool POLARPOINTcollinear(PolarPoint const p, PolarPoint const q,
                         PolarPoint const r);