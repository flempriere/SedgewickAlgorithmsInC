/*
Interface for a point data structure representing a point in a 2d plane.
*/

typedef double Number;

typedef struct {
    Number x; 
    Number y;
} point;

double distance(point p, point q);