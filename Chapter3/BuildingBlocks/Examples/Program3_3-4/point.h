/*
Program 3.3

Interface for a point data structure representing a point in a 2d plane.
*/


/**
 * @brief localised typedef for number type being used
 * 
 */
typedef double Number;

typedef struct {
    Number x; 
    Number y;
} point;

/**
 * @brief Compute the euclidean distance
 * between two points.
 * 
 * @param p point
 * @param q point
 * @return double
 */
double distance(point p, point q);