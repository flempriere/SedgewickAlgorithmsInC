/*
Exercise 2-7:
    Determine for what values of N is 2*N*H_n - N < Nlg(N) + 10N
    where H_n is the n-th harmonic number

    H_n approx = ln(N) + 0.5
    -> 2*N*H_N - N ~= 2*Nln(N) + 2*N*0.5 - N = 2*N*Ln(N)
    -> so approx 2*N*ln(N) < Nlg(N) + 10N
    -> N*ln(N) < 10*N
    ln(N) approx 10 when N = 2^10
*/

#include <tgmath.h>
#include <stdio.h>

#define eps 1e-6
long double newtons_method(long double (*f)(long double), long double x);
long double fn(long double x); 

int main(int argc, char *argv[argc + 1]) {
    long double N_0 = 0.0L;
    long double N_1 = 2e+10L;
    N_0 = newtons_method(fn, N_0);
    N_1 = newtons_method(fn, N_1);
    printf("solution: %Lf ~< N ~< %Lf\n", N_0, N_1);
}

long double n_harmonic(long double x) {
    long double euler_constant = 0.57721;
    return log(x) + euler_constant + 1.0L/(12.0L*x);
}

long double fn(long double x) {
    return 2*x*n_harmonic(x) - 11*x - x*log2(x);
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