/**
 * @file ex2_19.c
 * @author Felix Lempriere
 * @brief *Give the largest value of N for which you can solve
 * a problem requiring $f\left(N\right)$ instructions on a machine that can
 * execute $10^9$ instructions per second for the following functions
 * 1. $N^{3/2}$
 * 2. $N^{5/4}$
 * 3. $2NH_{n}$
 * 4. $N\lg\left(N\right)\lg\left(\lg\left(N\right)\right)$
 * 5. $N^2\lg\left(N\right)$
 *
 * We take the largest value to mean that the computation completes in less than
 * a second.
 * @version 0.1
 * @date 2025-04-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "MacroLibrary/Mathematics.h"

#include <stdio.h>
#include <stdlib.h>

long double TARGET = 1e+9;

long double n_cubed_square_root(long double const x);

long double n_quintic_quartic_root(long double const x);

long double two_n_times_harmonic(long double const x);

long double n_lg_n_lglg_n(long double const x);

long double n_squared_lg_n(long double const x);

constexpr size_t n_functions = 5u;
int main(int argc, char* argv[argc + 1]) {
    long double (*functions[n_functions])(
        long double) = { n_cubed_square_root, n_quintic_quartic_root,
                         two_n_times_harmonic, n_lg_n_lglg_n, n_squared_lg_n };

    char* fn_description[n_functions] = { "N^(3/2)", "N^(5/4)", "2NH_n",
                                          "NlgNlglgN", "N^2lgN" };

    long double x_0[n_functions] = { 1e+7, 1e+7, 1e+9, 1e+3, 1e+3 };

    for (register size_t i = 0; i < n_functions; i++) {
        printf("%s:  \tN = %Lf\n", fn_description[i],
               MATHnewtons_method(functions[i], x_0[i]));
    }
    return EXIT_SUCCESS;
}

long double n_cubed_square_root(long double const x) {
    return pow(x, 3.0 / 2.0) - TARGET;
}

long double n_quintic_quartic_root(long double const x) {
    return pow(x, 5.0 / 4.0) - TARGET;
}

long double two_n_times_harmonic(long double const x) {
    return 2 * x * MATHharmonic_number(x) - TARGET;
}

long double n_lg_n_lglg_n(long double const x) {
    return x * log2(x) * log2(log2(x)) - TARGET;
}

long double n_squared_lg_n(long double const x) {
    return x * x * log2(x) - TARGET;
}
