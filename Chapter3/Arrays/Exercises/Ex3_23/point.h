/*
Interface for a point data structure representing a point in a d-dimensional
space
*/
#include <stddef.h>

#define TOLERANCE 10e-4
#define MAX_DIM 10

typedef double Number;
typedef size_t Dimension;

typedef struct {
    Number x[MAX_DIM];
} point;

double distance(point p, point q, Dimension d);