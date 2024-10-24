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

#include <tgmath.h>
#include <stdio.h>

#define eps 1e-6
long double newtons_method(long double (*f)(long double), long double x);
long double fn1(long double x); 
long double fn2(long double x);

int main(int argc, char *argv[argc + 1]) {
    long double N_0 = 1.0L;
    long double N_1 = 8.0L;

    long double f1N_0 = newtons_method(fn1, N_0);
    long double f1N_1 = newtons_method(fn1, N_1);

    printf("N^(3/2) > Nlg(N)^2/2 for %Lf ~< N ~< %Lf\n", f1N_0, f1N_1);

    long double f2N_0 = newtons_method(fn2, N_0);
    long double f2N_1 = newtons_method(fn2, N_1);

    printf("N^(3/2) > 2Nlg(N)^2 for %Lf ~< N ~< %Lf\n", f2N_0, f2N_1);

    long double lb = (f1N_0 > f2N_0) ? f1N_0 : f2N_0;
    long double ub = (f1N_1 < f2N_0) ? f1N_1 : f2N_1;

    printf("N^(3/2) mutually largest for %Lf ~< N ~< %Lf\n", lb, ub);

}

long double fn1(long double x) {
    return x*pow(log2(x), 2) / 2 - pow(x, 3.0L/2.0L);
}

long double fn2(long double x) {
    return 2*x*pow(log2(x), 2) - pow(x, 3.0L/2.0L);
}

long double newtons_method(long double (*f)(long double), long double x) {
    long double h = eps;
    while(fabs((*f)(x)) > eps) {
        long double xph = (*f)(x + h);
        long double xmh = (*f)(x - h);
        long double dx = (xph - xmh) / (2.0L*h);
        x -= ((*f)(x) / dx);
    }
    return x;
}