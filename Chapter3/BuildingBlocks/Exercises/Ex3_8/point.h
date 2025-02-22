/*
Interface for a point data structure representing a point in a 2d plane.
*/

/**
 * @brief Numerical tolerance for
 * collinear calculation.
 * 
 */
#define TOLERANCE 10e-4

/**
 * @brief Localises numerical data definition
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

/**
 * @brief Determines if three points are collinear
 * to within a tolerance factor.
 * 
 * @param p point
 * @param q point
 * @param r point
 * @return true if collinear else
 * @return false 
 * 
 * @see TOLERANCE
 */
bool isCollinear(point p, point q, point r);