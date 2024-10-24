/*
Exercise 2-5:
    Determine for what values of N, 10Nlg(N) > 2N**2

    10*2*lg(2) = 20
    2*(2**2) = 8 -> first root < 2
    10*36*lg(36) = 360*(5) = 1800
    2*(36*36) = 2500+
    second root < 36
*/

#include <tgmath.h>
#include <stdio.h>

#define eps 1e-6
long double newtons_method(long double (*f)(long double), long double x);
long double fn(long double x); 
long double quadraticTerm(long double x);
long double logTerm(long double x);

int main(int argc, char *argv[argc + 1]) {
    long double N_0 = 2.0L;
    long double N_1 = 36.0L;
    N_0 = newtons_method(fn, N_0);
    N_1 = newtons_method(fn, N_1);
    printf("10Nlg(N) > 2N^2 for %Lf ~< N ~< %Lf\n", N_0, N_1);
}

long double logTerm(long double x) {
    return 10.0L*x*log2(x);
}

long double quadraticTerm(long double x) {
    return 2*pow(x, 2);
}

long double fn(long double x) {
    return logTerm(x) - quadraticTerm(x);
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