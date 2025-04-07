/**
 * @file Point.h
 * @author Felix Lempriere
 * @brief Program 3.3: Interface for the Point type.
 *
 * This header file defines the interface for a Point type representing points
 * in a 2D space.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */
#pragma once

/**
 * @brief localised typedef for number type being used
 *
 */
typedef double Number;

typedef struct {
    Number x;
    Number y;
} Point;

/**
 * @brief Compute the euclidean distance
 * between two points.
 *
 * @param p point
 * @param q point
 *
 * @post double >= 0
 * @return double distance between two points.
 */
double POINTdistance(Point const p, Point const q);