/**
 * @file Triangle.h
 * @author Felix Lempriere
 * @brief Interface for a triangle data type consisting of three points.
 *
 * Supports generating a random triangle and calculating the area of triangle.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
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
 * @param t triangle to calculate the area of.
 *
 * @post area >= 0.0.
 * @return double, positive area.
 */
double TRIANGLEarea(Triangle const t);

/**
 * @brief Generate a random triangle with points in
 * the unit square.
 *
 * @post All points p_i in the triangle are in the unit square.
 * @return Triangle random triangle in the unit square.
 */
Triangle TRIANGLErandom(void);
