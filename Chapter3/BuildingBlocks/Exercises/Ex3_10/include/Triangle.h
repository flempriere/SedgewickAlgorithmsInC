/**
 * @brief Triangle interface for Exercise 3.10
 *
 */
#pragma once
#include "Point/v3/Point_v3.h"

/**
 * @brief Triangle representation consisting
 * of three vertices represented as points
 * in a 2D plane.
 */
typedef struct {
    Point a;
    Point b;
    Point c;
} Triangle;

/**
 * @brief Calculates the area of a triangle @t using
 * Heron's formula.
 *
 * @param t triangle
 * @return double
 */
double TRIANGLEarea(Triangle const t);

/**
 * @brief Generate a random triangle with points in
 * the unit square.
 *
 * @return Triangle
 */
Triangle TRIANGLErandom(void);
