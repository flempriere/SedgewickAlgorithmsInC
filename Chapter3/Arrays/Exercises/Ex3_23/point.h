/*
Interface for a point data structure representing a point in a d-dimensional
space
*/
#include <stddef.h>

/**
 * @brief Numerical tolerance
 * for Collinear check
 * 
 */
#define TOLERANCE 10e-4

/**
 * @brief Maximum dimension for
 * points
 * 
 */
#define MAX_DIM 10

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
    Number x[MAX_DIM];
} point;

/**
 * @brief Calculates the distance
 * between two points
 * 
 * @param p point
 * @param q point
 * @param d dimension, p,q must have the same dimension d
 * @return double 
 */
double distance(point p, point q, Dimension d);