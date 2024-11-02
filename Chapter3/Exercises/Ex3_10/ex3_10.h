/*
Interface Exercise 3.10.

Contains the point.h interface seen previously + an interface for triangles
and the randNum interface.
*/

//point interface
#define TOLERANCE 10e-4

typedef double Number;

typedef struct {
    Number x; 
    Number y;
} point;

double distance(point p, point q);
double slope(point p, point q);

bool isCollinear(point p, point q, point r);

//triangle interface

typedef struct {
    point a;
    point b;
    point c;
} triangle;

double area(triangle t);

//randNum interface
Number randNum(void);
