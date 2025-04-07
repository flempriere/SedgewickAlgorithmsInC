/**
 * @file Mathematics.h
 * @author Felix Lempriere
 * @brief A collection of useful mathematical functions, procedures and macros.
 * @version 0.1
 * @date 2025-04-05
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

#include "MacroLibrary/TraceMacro.h"

#include <tgmath.h>

/**
 * @brief Tolerance value used to determine convergence or equality in
 * iterative methods and floating point comparisons.
 */
constexpr long double MATHeps = 1e-6L;

/**
 * @brief Uses [Newton's
 * method](https://en.wikipedia.org/wiki/Newton%27s_method) to find a root of
 * the function `MATHf`, starting with an initial guess `MATHx`.
 *
 * Iterates until |f(x)| < eps.
 *
 * @param MATHf Pointer to the function whose root is to be found.
 * @param MATHx Initial guess for the root.
 * @return long double, the root of the function if found, or NaN if the
 * function fails to converge.
 *
 * @see eps
 */
static inline long double MATHnewtons_method(long double MATHf(long double),
                                             long double MATHx) {
    register long double const h = MATHeps;
    while (fabs(MATHf(MATHx)) > MATHeps) {
        register long double const xph = MATHf(MATHx + h);
        register long double const xmh = MATHf(MATHx - h);
        register long double const dx = (xph - xmh) / (2.0L * h);
        if (fabs(dx) < MATHeps) {
            TRACE_VALUE("Error: Derivative is zero or too small.", dx);
            return NAN;    // Return NaN to indicate failure
        }
        MATHx -= (MATHf(MATHx) / dx);
    }
    return MATHx;
}