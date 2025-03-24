/*
Exercise 2-6:
    Determine for what values of N is N^(3/2) between N(lg(N)^2)/2
    and 2N(lgN)^2

    for N < 1 -> N^(3/2) -> small positive, N = 1, positive
    lg(N) -> -inf -> lg(N)^2 -> inf, but zeroed implies first crossover near 1

    sqrt(4) = 2, 2^3 = 8
    lg(4) = 2 -> Nlg(N)^2/2 = 4*2*2/2 = 8
    2N(lgN)^2 = 2*2*2*2 = 16
    so second root is around 4
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
#define eps 1e-6

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
 * @brief Calculates N(lg(N)^2/2) - N^(3/2)
 *
 * @param x
 * @return long double
 */
long double fn1(long double const x);

/**
 * @brief Calculates 2N(lg(N)^2)
 *
 * @param x
 * @return long double
 */
long double fn2(long double const x);

/**
 * @brief Finds the regions where N^(3/2) is
 * between Nlg(N)^2/2 and 2Nlg(N)^2.
 *
 * @return EXIT_SUCCESS on completion
 */
int main(int argc, char* argv[argc + 1]) {
    long double const N_0 = 1.0L;
    long double const N_1 = 8.0L;

    long double f1N_0 = newtons_method(fn1, N_0);
    long double f1N_1 = newtons_method(fn1, N_1);

    printf("N^(3/2) > Nlg(N)^2/2 for %Lf ~< N ~< %Lf\n", f1N_0, f1N_1);

    long double f2N_0 = newtons_method(fn2, N_0);
    long double f2N_1 = newtons_method(fn2, N_1);

    printf("N^(3/2) > 2Nlg(N)^2 for %Lf ~< N ~< %Lf\n", f2N_0, f2N_1);

    printf("N^(3/2) between Nlg(N)^2/2 and 2Nlg(N)^2"
           " in the intervals:\n(%Lg, %Lg) and (%Lg, %Lg)\n",
           f1N_0, f2N_0, f2N_1, f1N_1);

    return EXIT_SUCCESS;
}

long double fn1(long double const x) {
    return x * pow(log2(x), 2) / 2 - pow(x, 3.0L / 2.0L);
}

long double fn2(long double const x) {
    return 2 * x * pow(log2(x), 2) - pow(x, 3.0L / 2.0L);
}

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