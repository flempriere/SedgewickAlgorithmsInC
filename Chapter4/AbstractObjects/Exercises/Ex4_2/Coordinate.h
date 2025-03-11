/**
 * @file Coordinate.h
 * @author Felix Lempriere
 * @brief Uses the floating point item interface from exercise
 * 4.2 to provide an abstract coordinate representation for a
 * point
 * 
 * @version 0.1
 * @date 2024-12-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <tgmath.h>

/**
 * @brief Obscure underlying float representation
 * 
 */
typedef double Coordinate;

/**
 * @brief tolerance for floating point equality
 * 
 */
#define TOL 1e-6

/**
 * @brief Test for equality of two items
 * 
 * @param A 
 * @param B 
 * @return true i equal else
 * @return false 
 */
inline bool CoordinateEq(Coordinate A, Coordinate B) {
    Coordinate lgst = (fabs(A) > fabs(B)) ? fabs(A) : fabs(B);
    if (lgst == 0) return true; // both are zero.
    return (fabs(A - B) / lgst < TOL); 
}

