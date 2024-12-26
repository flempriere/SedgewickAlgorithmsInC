/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Item interface for points in a plane including
 * equality test
 * @version 0.1
 * @date 2024-12-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "point.h"

/**
 * @brief Obscure the point type
 * 
 */
typedef point Item;

#define eq(A, B) (PointEq(A, B))