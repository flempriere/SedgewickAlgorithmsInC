/*
Exercise 2-5:
    Determine for what values of N, 10Nlg(N) > 2N**2

    10*2*lg(2) = 20
    2*(2**2) = 8 -> first root < 2
    10*32*lg(32) = 320*(5) = 1600
    2*(36*36) = 2500+
    second root < 36
*/

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Tolerance value for root finding
 * with newtons_method.
 *
 * @see newtons_method
 */
constexpr long double eps = 1e-6L;

/**
 * @brief Finds a root of the the function @f
 * using [newtons method](https://en.wikipedia.org/wiki/Newton%27s_method)
 * with an initial guess of x
 *
 * Stops once f(x) < eps
 *
 * @param f
 * @param x
 * @return long double, root of f if found
 *
 * @see eps
 */
long double newtons_method(long double (*const f)(long double), long double x);

/**
 * @brief evaluates 10\lg(x) - 2x^2
 *
 *
 * @param x
 * @return long double
 */
long double fn(long double const x);
long double quadraticTerm(long double const x);
long double logTerm(long double const x);

/**
 * @brief Finds the two roots of 10Nlg(N) - 2N^2
 * to determine the region 10Nlg(N) > 2N^2.

 * @return EXIT_SUCCESS on completion
 */
int main(int argc, char* argv[argc + 1]) {
    long double N_0 = 2.0L;
    long double N_1 = 36.0L;
    N_0 = newtons_method(fn, N_0);
    N_1 = newtons_method(fn, N_1);
    printf("10Nlg(N) > 2N^2 for %Lf ~< N ~< %Lf\n", N_0, N_1);

    return EXIT_SUCCESS;
}

long double logTerm(long double const x) { return 10.0L * x * log2(x); }

long double quadraticTerm(long double const x) { return 2 * pow(x, 2); }

long double fn(long double const x) { return logTerm(x) - quadraticTerm(x); }

long double newtons_method(long double (*const f)(long double), long double x) {
    register long double const h = eps;
    while (fabs((*f)(x)) > eps) {
        register long double const xph = (*f)(x + h);
        register long double const xmh = (*f)(x - h);
        register long double const dx = (xph - xmh) / (2.0L * h);
        x -= ((*f)(x) / dx);
    }
    return x;
}