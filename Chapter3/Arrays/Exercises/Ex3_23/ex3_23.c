/*
Exercise 3.23

Modify Program 3.8 to work for a d-dimensional point.
*/

#include <tgmath.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"

double randFloat(void);

int main(int argc, char* argv[argc + 1]) {

    if (argc != 4) {
        fprintf(stderr, "Error: requires args dim, N, d\n");
        return 1;
    }

    Dimension dim = strtoull(argv[1], NULL, 0);
    dim = (dim < MAX_DIM) ? dim : MAX_DIM;
    size_t N = strtoull(argv[2], NULL, 0);
    double d = atof(argv[3]);

    point* a = malloc(N*(sizeof(typeof_unqual(*a))));

    for (size_t i = 0; i < N; i++) {
        for (Dimension idx = 0; idx < dim; idx++) {
            a[i].x[idx] = randFloat();
        }
    }

    size_t count = 0;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = i+1; j < N; j++) {
            if (distance(a[i], a[j], dim) < d) {
                count++;
            }
        }
    }
    printf("%zu edges shorter than %f\n", count, d);

    return 0;
}

double randFloat(void) {
    return 1.0*rand() / RAND_MAX;
}