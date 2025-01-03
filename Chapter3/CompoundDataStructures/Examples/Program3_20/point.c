/*
Provides the implementation for the distance function provided in point.h
*/

#include <tgmath.h>
#include "point.h"
#include <stdio.h>

double distance(point p, point q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx*dx + dy*dy);
}

bool isCollinear(point p, point q, point r) {
    double m_pq = (q.y - p.y) / (q.x - p.x);
    double m_qr = (r.y - q.y) / (r.x - q.x);
    return (fabs(m_pq - m_qr) < TOLERANCE);
}