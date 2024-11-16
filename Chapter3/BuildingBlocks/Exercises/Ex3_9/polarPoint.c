/*
Exercise 3.9

Implementation for the point interface using a polar coordinate representation
*/

/*
Provides the implementation for the distance function provided in point.h
*/

#include <tgmath.h>
#include "point.h"
#include <stdio.h>

static double getXcoord(point p) {
    return p.r * cos(p.theta);
}

static double getYcoord(point p) {
    return p.r * sin(p.theta);
}

double distance(point p, point q) {
    double dx = getXcoord(p) - getXcoord(q);
    double dy = getYcoord(p) - getYcoord(q);
    return sqrt(dx*dx + dy*dy);
}

bool isCollinear(point p, point q, point r) {
    double m_pq = (getYcoord(q) - getYcoord(p)) / (getXcoord(q) - getXcoord(p));
    double m_qr = (getYcoord(q) - getYcoord(r)) / (getXcoord(q) - getXcoord(r));
    return (fabs(m_pq - m_qr) < TOLERANCE);
}