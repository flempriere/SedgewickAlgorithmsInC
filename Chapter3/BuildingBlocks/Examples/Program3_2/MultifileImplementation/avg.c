/*
Multifile implementation of Program 3.2 that utilises a client file (avg.c)
an interface file (num.h) and an implementation file (num.c)
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