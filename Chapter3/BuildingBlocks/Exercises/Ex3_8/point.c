/*
Provides the implementation for the distance function provided in point.h
*/

#include <tgmath.h>
#include "point.h"
#include <stdio.h>

/**
 * @brief Check if two points are equal
 * 
 * @param p point
 * @param q point
 * @return true  if points equal,
 * @return false if points differ
 */
static bool isEqual(point p, point q) {
    return distance(p, q) < TOLERANCE;
}

double distance(point p, point q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx*dx + dy*dy);
}

bool isCollinear(point p, point q, point r) {
    /*if two of the points are the same then
    always colinear with third */
    if (isEqual(p, q) || isEqual(q, r)) {
        return true;
    }

    double m_pq = (q.y - p.y) / (q.x - p.x);
    double m_qr = (r.y - q.y) / (r.x - q.x);
    return (fabs(m_pq - m_qr) < TOLERANCE);
}