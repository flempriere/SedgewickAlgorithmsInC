/**
 * @file Point_v2.h
 * @author Felix Lempriere
 * @brief Version 2 of the Interface for the Point type.
 *
 * This header file defines the interface for a Point type representing points
 * in a 2D space.
 *
 * This extends the interface in Program 3.3 to support a  colinearity test
 * on three points.
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
constexpr double POINTTOLERANCE = 10e-4;

/**
 * @brief Localises numerical data definition
 *
 */
typedef double Number;

/**
 * @brief Two-dimensional Point data type
 * consisting of an x and y coordinate.
 *
 */
typedef struct {
    Number x;
    Number y;
} Point;

/**
 * @brief Calculates the euclidean distance
 * between two points.
 *
 * @param p point
 * @param q point
 * @return double
 */
double POINTdistance(Point const p, Point const q);

/**
 * @brief Check if two points are equal
 *
 * @param p point
 * @param q point
 * @return true  if points equal,
 * @return false if points differ
 */
static inline bool POINTequal(Point const POINTp, Point const POINTq) {
    return POINTdistance(POINTp, POINTq) < POINTTOLERANCE;
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
 * @see POINTTOLERANCE
 */
bool POINTcollinear(Point const p, Point const q, Point const r);