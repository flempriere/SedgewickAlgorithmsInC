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
 * Iterates until |f(x)| < MATHeps.
 *
 * @param MATHf Pointer to the function whose root is to be found.
 * @param MATHx Initial guess for the root.
 * @return long double, the root of the function if found, or NaN if the
 * function fails to converge.
 *
 * @see MATHeps
 */
static inline long double MATHnewtons_method(long double MATHf(long double),
                                             long double MATHx) {
    register long double const MATHh = MATHeps;
    while (fabs(MATHf(MATHx)) > MATHeps) {
        register long double const MATHxph = MATHf(MATHx + MATHh);
        register long double const MATHxmh = MATHf(MATHx - MATHh);
        register long double const MATHdx =
            (MATHxph - MATHxmh) / (2.0L * MATHh);
        if (fabs(MATHdx) < MATHeps) {
            TRACE_VALUE("Error: Derivative is zero or too small.", MATHdx);
            return NAN;    // Return NaN to indicate failure
        }
        MATHx -= (MATHf(MATHx) / MATHdx);
    }
    return MATHx;
}

/**
 * @brief Computes ceil(lg(MATHn))
 * 
 * @param MATHn integer to compute ceil(lg()) of must be > 0
 * @return unsigned 
 */
static inline unsigned MATHlg(size_t MATHn) {
    register unsigned MATHlgN;
    for (MATHlgN = 0; MATHn > 0; MATHlgN++, MATHn /= 2);
    return MATHlgN;
}

static inline long double MATHharmonic_number(long double const MATHx) {
    if (MATHx == 1)
        return 1.0L;
    else if (MATHx == 2)
        return 1.5L;

    constexpr long double MATHEULER_CONSTANT = 0.57721L;
    return log(CAST(long double) MATHx) + MATHEULER_CONSTANT +
           1.0L / (12.0L * MATHx);
}