/*
Provides the implementation for the distance function provided in point.h
*/

#include <tgmath.h>
#include "Point_v2.h"

/**
 * @brief Check if two points are equal
 * 
 * @param p point
 * @param q point
 * @return true  if points equal,
 * @return false if points differ
 */
static bool isEqual(Point p, Point q) {
    return POINTdistance(p, q) < TOLERANCE;
}

double POINTdistance(Point p, Point q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx*dx + dy*dy);
}

bool POINTisCollinear(Point p, Point q, Point r) {
    /*if two of the points are the same then
    always colinear with third */
    if (isEqual(p, q) || isEqual(q, r)) {
        return true;
    }

    double m_pq = (q.y - p.y) / (q.x - p.x);
    double m_qr = (r.y - q.y) / (r.x - q.x);
    return (fabs(m_pq - m_qr) < TOLERANCE);
}