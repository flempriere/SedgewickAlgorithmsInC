/*
Exercise 3.10: Concrete implementation of the triangle datatype

We use Heron's formula to compute the area.
*/

#include "ex3_10.h"
#include <stdio.h>
#include <tgmath.h>


double area(triangle t) {
    /*         (b)
    *      [ab]     [bc]
    *   (a)    [ac]    (c)
    */
    double ab = distance(t.a, t.b);
    double ac = distance(t.a, t.c);
    double bc = distance(t.b, t.c);

    double s = 0.5*(ab + ac + bc);
    double discrim = s*(s - ab)*(s - ac)*(s - bc);
    return sqrt(discrim);
}