/**
 * @brief Updated Point interface including a test for colinearity.
 *
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
} Point;

/**
 * @brief Calculates the euclidean distance
 * between two points.
 *
 * @param p point
 * @param q point
 * @return double
 */
double POINTdistance(Point p, Point q);

/**
 * @brief Check if two points are equal
 *
 * @param p point
 * @param q point
 * @return true  if points equal,
 * @return false if points differ
 */
static inline bool POINTis_equal(Point p, Point q) {
    return POINTdistance(p, q) < TOLERANCE;
}

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
bool POINTisCollinear(Point p, Point q, Point r);