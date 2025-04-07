/**
 * @file Point_dDim.h
 * @author Felix Lempriere
 * @brief Version of the Point interface supporting a d-dimensional point.
 *
 * Extends the Point interface with POINTrandom, to generate random points.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */
#pragma once

#include <stddef.h>

/**
 * @brief Maximum dimension for
 * points
 *
 */
constexpr size_t POINT_DDIMMAX_DIM = 10u;

/**
 * @brief Localises numeric type
 * reference
 *
 */
typedef double Number;

/**
 * @brief Number of dimensions
 * point is represented in.
 */
typedef size_t Dimension;

/**
 * @brief Two dimensional point
 * represented by an x and y
 * coordinate.
 *
 */
typedef struct {
    Dimension dim;
    Number x[POINT_DDIMMAX_DIM];
} Point_DDIM;

/**
 * @brief Calculates the distance
 * between two points
 *
 * @param p point
 * @param q point
 * @param d dimension, p,q must have the same dimension d
 * @return double
 */
double POINT_DDIMdistance(Point_DDIM const p, Point_DDIM const q);