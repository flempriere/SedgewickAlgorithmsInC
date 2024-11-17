/*
Interface Exercise 3.10.

Contains the point.h interface seen previously + an interface for triangles
and the randNum interface.
*/

//point interface

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
 * @brief Calculates the slope between
 * two points.
 * 
 * @param p point
 * @param q point
 * @return double 
 */
double slope(point p, point q);

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

//triangle interface

/**
 * @brief Triangle representation consisting
 * of three vertices represented as points
 * in a 2D plane.
 */
typedef struct {
    point a;
    point b;
    point c;
} triangle;

/**
 * @brief Calculates the area of a triangle @t using
 * Heron's formula.
 * 
 * @param t triangle 
 * @return double 
 */
double area(triangle t);

//randNum interface

/**
 * @brief Generate a double between
 * 0 and 1.
 */
Number randNum(void);
