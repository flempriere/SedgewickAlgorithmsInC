/*
Program 3.7

This program runs a coin flipping experiment M times with each runc consisting
of N flips. An array f keeps track of the frequency of occurance of 0 <= i <= N
where i is the number of heads.

A histogram is then printed out, with one asterisk corresponding to 10
occurences.

The operation on which this program is based -- indexing an array with computed
value -- is critical to the efficiency of many computational procedures

utilises C23 bool, use _Bool or <stdbool.h> for older standards
*/

#include <stdlib.h>
#include <stdio.h>

bool heads(void);

int main(int argc, char* argv[argc + 1]) {
    
    if (argc != 3) {
        fprintf(stderr, "Error: requires arguments N and M\n");
        return 1;
    }
    size_t N = strtoull(argv[1], NULL, 0);
    size_t M = strtoull(argv[2], NULL, 0);

    size_t* f = malloc((N+1)*sizeof(typeof_unqual(*f)));
    for (size_t j = 0; j <= N; j++) f[j] = 0;

    for (size_t i = 0; i < M; i++) {
        size_t cnt = 0;
        for (size_t j = 0; j <= N; j++) {
            if (heads()) cnt++;
        }
        f[cnt]++;
    }
    for (size_t j = 0; j <= N; j++) {
        printf("%2zu ", j);
        for (size_t i = 0; i < f[j]; i += 10) printf("*");
        printf("\n");
    }
    return 0;
}

bool heads(void) {
    return rand() < RAND_MAX /2;
}
