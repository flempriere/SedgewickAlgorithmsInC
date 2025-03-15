/*
Exercise 3.9

Implementation for the point interface using a polar coordinate representation
*/

/*
Provides the implementation for the distance function provided in point.h
*/

#include <tgmath.h>
#include "PolarPoint.h"

static bool isEqual(Point p, Point q) {
    return POINTdistance(p, q) < TOLERANCE;
}

static double getXcoord(Point p) {
    return p.r * cos(p.theta);
}

static double getYcoord(Point p) {
    return p.r * sin(p.theta);
}

double POINTdistance(Point p, Point q) {
    double dx = getXcoord(p) - getXcoord(q);
    double dy = getYcoord(p) - getYcoord(q);
    return sqrt(dx*dx + dy*dy);
}

bool POINTisCollinear(Point p, Point q, Point r) {
    //if two points equal, collinear
    if (isEqual(p, q) || isEqual(q, r)) {
        return true;
    }
    double m_pq = (getYcoord(q) - getYcoord(p)) / (getXcoord(q) - getXcoord(p));
    double m_qr = (getYcoord(q) - getYcoord(r)) / (getXcoord(q) - getXcoord(r));
    return (fabs(m_pq - m_qr) < TOLERANCE);
}