/*
Provides the implementation for the distance function provided in point.h
*/

#include "Point_v2.h"

#include <tgmath.h>

double POINTdistance(Point p, Point q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx * dx + dy * dy);
}

bool POINTisCollinear(Point p, Point q, Point r) {
    /*if two of the points are the same then
    always colinear with third */
    if (POINTis_equal(p, q) || POINTis_equal(q, r)) { return true; }

    double m_pq = (q.y - p.y) / (q.x - p.x);
    double m_qr = (r.y - q.y) / (r.x - q.x);
    return (fabs(m_pq - m_qr) < TOLERANCE);
}