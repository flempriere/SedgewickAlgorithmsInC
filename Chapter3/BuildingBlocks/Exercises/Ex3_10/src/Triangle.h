/**
 * @brief Triangle interface for Exercise 3.10
 * 
 */
 #pragma once
 #include "Point_v3.h"

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
double TRIANGLEarea(Triangle t);

