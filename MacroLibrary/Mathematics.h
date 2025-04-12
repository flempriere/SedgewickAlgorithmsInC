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
 * @brief Constant value for Pi
 *
 */
constexpr long double MATHPI = 3.14159265358979323846L;

/**
 * @brief Constant value for e
 *
 */
constexpr long double MATHe = 2.7182818284590451L;

/**
 * @brief Constant value for the Euler-Mascaroni constant
 * 
 */
constexpr long double MATHEULER_CONSTANT = 0.5772156649015L;

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

static inline long double MATHharmonic_number(long double const MATHx) {
    if (fabs(MATHx - 1.0) < MATHeps)
        return 1.0L;
    else if (fabs(MATHx - 2.0) < MATHeps)
        return 1.5L;
    return log(CAST(long double) MATHx) + MATHEULER_CONSTANT +
           1.0L / (12.0L * MATHx);
}

/**
 * @brief Calculates the principal branch of the Lambert W function.
 *
 * @details
 * The Lambert W function is the inverse to z = we^w. This function computes
 * the value for the principal branch, and is well defined on the real
 * numbers >= 1.
 *
 * @remark We use Boyd's formula to approximate the solution:
 * ```math
 *\begin{align}
 * w_{n + 1} &= \frac{w_{n}}{1 + w_n}\left(1 +
 *\log\left(\frac{z}{w_n}\right)\right)
 *\end{align}
 *```
 * @note
 * Boyd's formula and choice of w_0 derived from
 *https://en.wikipedia.org/wiki/Lambert_W_function#Numerical_evaluation
 * @param z Argument of the Lambert W function
 * @return long double
 */
static inline long double MATHLambert_W0(long double const MATHz) {

    // initialise w0;
    register long double w;
    if (MATHz > MATHe) {
        w = (log(MATHz) - log(log(MATHz)));
    } else if (MATHz > 0.0) {
        w = MATHz/MATHe;
    } else if (MATHz > -1.0/MATHe) {
        register long double discrim = sqrt(1 + MATHe * MATHz);
        register long double ez = MATHe * MATHz;
        w = (ez * log(1.0 + discrim))/(1.0 + ez + discrim);
    } else {
        return NAN;
    }

    while (fabs(MATHz - w * exp(w)) > MATHeps) {
        w = (w / (1.0L + w)) * (1.0L + log(MATHz / w));
    }
    return w;
}