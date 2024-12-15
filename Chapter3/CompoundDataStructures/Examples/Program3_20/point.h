/*
Interface for a point data structure representing a point in a 2d plane.
*/

/**
 * @brief Numerical tolerance
 * for collinear calculations.
 * 
 */
#define TOLERANCE 10e-4

/**
 * @brief localises numerical definition
 * 
 */
typedef double Number;

/**
 * @brief Two-dimensional point represented
 * by an x and y coordinate.
 * 
 */
typedef struct {
    Number x; 
    Number y;
} point;

/**
 * @brief Calculates the distance between two points.
 * 
 * @param p point
 * @param q point
 * @return double 
 */
double distance(point p, point q);

/**
 * @brief Determines if three points are
 * collinear.
 * 
 * @param p point
 * @param q point
 * @param r point
 * @return true if collinear else
 * @return false 
 */
bool isCollinear(point p, point q, point r);