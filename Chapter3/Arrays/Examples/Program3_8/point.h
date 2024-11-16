/*
Interface for a point data structure representing a point in a 2d plane.
*/

#define TOLERANCE 10e-4

typedef double Number;

typedef struct {
    Number x; 
    Number y;
} point;

double distance(point p, point q);

bool isCollinear(point p, point q, point r);