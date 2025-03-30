/*
Exercise 3.10: Concrete implementation of the triangle datatype

We use Heron's formula to compute the area.
*/

#include "Triangle.h"

#include "Point_v3.h"

#include <tgmath.h>

double TRIANGLEarea(Triangle const t) {
    /*          (b)
     *      [ab]    [bc]
     *   (a)    [ac]    (c)
     */
    double const ab = POINTdistance(t.a, t.b);
    double const ac = POINTdistance(t.a, t.c);
    double const bc = POINTdistance(t.b, t.c);

    double const s = 0.5 * (ab + ac + bc);
    double const discrim = s * (s - ab) * (s - ac) * (s - bc);
    return sqrt(discrim);
}

Triangle TRIANGLErandom(void) {
    return (Triangle) { .a = POINTrandom(),
                        .b = POINTrandom(),
                        .c = POINTrandom() };
}