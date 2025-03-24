/*
Interface for a point data structure representing a point in a 2d plane,
using a polar representation
*/

/**
 * @brief Numerical tolerance for
 * collinear calculation.
 *
 */
constexpr long double POLARPOINTTOLERANCE = 10e-4L;

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
    Number r;
    Number theta;
} PolarPoint;

/**
 * @brief Calculates the euclidean distance
 * between two points.
 *
 * @param p point
 * @param q point
 * @return double
 */
double POLARPOINTdistance(PolarPoint const p, PolarPoint const q);

/**
 * @brief Determine if two points p and q are equal to a given
 * tolerance.
 *
 * @param p
 * @param q
 * @return true
 * @return false
 */
static inline bool POLARPOINTis_equal(PolarPoint const p, PolarPoint const q) {
    return POLARPOINTdistance(p, q) < POLARPOINTTOLERANCE;
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
bool POLARPOINTis_collinear(PolarPoint const p, PolarPoint const q,
                            PolarPoint const r);