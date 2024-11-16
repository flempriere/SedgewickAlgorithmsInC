/*
Exercise 3.5. Implement a version of Program 3.2 that supports bit types
(values that can be zero or one)
*/
#include <tgmath.h>
#include <stdlib.h>
#include <stdio.h>
#include "num.h"


int main(int argc, char* argv[argc + 1]) {

    int N = atoi(argv[1]);
    double m1 = 0.0;
    double m2 = 0.0;

    Number x;

    for (size_t i = 0; i < N; i++) {
        x = randNum();
        m1 += ((double) x)/N;
        m2 += ((double) x*x) / N; 
    }
    printf("       Average: %f\n", m1);
    printf("Std. deviation: %f\n", sqrt(m2 - m1*m1));

    return 0;
}