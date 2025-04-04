/**
 * @brief Updates the Point_v2 interface with a slope function.
 *
 */
#pragma once
#include "Number/v1/NumberDouble/NumberDouble.h"

/**
 * @brief Numerical tolerance equality calculations
 *
 */
constexpr double POINTTOLERANCE = 10e-4;

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
static inline bool POINTequal(Point const p, Point const q) {
    return POINTdistance(p, q) < POINTTOLERANCE;
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
 * @see TOLERANCE
 */
bool POINTcollinear(Point const p, Point const q, Point const r);

/**
 * @brief Generates a random point in the unit square.
 *
 * @return Point
 */
Point POINTrandom(void);