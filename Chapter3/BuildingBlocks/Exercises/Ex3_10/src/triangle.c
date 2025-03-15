/*
Exercise 3.10: Concrete implementation of the triangle datatype

We use Heron's formula to compute the area.
*/

#include "Point_v3.h"
#include "Triangle.h"
#include <tgmath.h>


double TRIANGLEarea(Triangle t) {
    /*         (b)
    *      [ab]     [bc]
    *   (a)    [ac]    (c)
    */
    double ab = POINTdistance(t.a, t.b);
    double ac = POINTdistance(t.a, t.c);
    double bc = POINTdistance(t.b, t.c);

    double s = 0.5*(ab + ac + bc);
    double discrim = s*(s - ab)*(s - ac)*(s - bc);
    return sqrt(discrim);
}