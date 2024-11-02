/*
Provides the implementation for the distance function provided in point.h
*/

#include <tgmath.h>
#include "ex3_10.h"

double distance(point p, point q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx*dx + dy*dy);
}

double slope(point p, point q) {
    return (q.y - p.y) / (q.x - p.x);
}

bool isCollinear(point p, point q, point r) {
    double m_pq = (q.y - p.y) / (q.x - p.x);
    double m_qr = (r.y - q.y) / (r.x - q.x);
    return (fabs(m_pq - m_qr) < TOLERANCE);
}