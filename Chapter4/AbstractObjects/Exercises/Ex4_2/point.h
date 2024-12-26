/**
 * @file point.h
 * @author Felix Lempriere
 * @brief header file containing the definition of a 
 * 2d planar point
 * @version 0.1
 * @date 2024-12-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include "Coordinate.h"

/**
 * @brief Structure representing a 2D cartesian
 * point with an x and y coordinate.
 * 
 */
typedef struct point point;

struct point {
    Coordinate x;
    Coordinate y;
};

/**
 * @brief Tests two points for equality using the
 * Coordinate data types equality representation.
 * 
 * @return true if equal else
 * @return false
 */
#define PointEq(P, Q) ((CoordinateEq(P.x, Q.x)) && CoordinateEq(P.y, Q.y))