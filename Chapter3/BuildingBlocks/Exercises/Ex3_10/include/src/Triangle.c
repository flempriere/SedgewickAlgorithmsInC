/**
 * @file Triangle.c
 * @author Felix Lempriere
 * @brief Implementation of the Triangle interface.
 *
 * Supports generating a random triangle and calculating the area of triangle.
 * Heron's formula is used to calculate the area of the triangle.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "../Triangle.h"

#include "Point/v3/Point_v3.h"

#include <assert.h>
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
    assert(discrim > 0 &&
           "Runtime Error: negative number calculated in area\n");
    return sqrt(discrim);
}

Triangle TRIANGLErandom(void) {
    return (Triangle) { .a = POINTrandom(),
                        .b = POINTrandom(),
                        .c = POINTrandom() };
}