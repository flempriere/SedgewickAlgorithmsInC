/*
Interface for a point data structure representing a point in a 2d plane.
*/

/**
 * @brief localises numeric type reference of point.
 * 
 */
typedef double Number;

/**
 * @brief Two-dimensional Point data type
 * consisting of an x and y coordinate.
 * 
 */
typedef struct {
    Number x; 
    Number y;
} point;

/**
 * @brief Calculates the euclidean distance
 * between two points.
 * 
 * @param p point
 * @param q point
 * @return double
 */
double distance(point p, point q);