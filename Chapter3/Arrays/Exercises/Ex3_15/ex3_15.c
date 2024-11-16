/*
Program 3.15
Determine the effect of removing the if (a[i]) test in the inner loop of
Program 3.5.
 
The approaches agree, but the program runs slower
*/
#include <stdio.h>
#include <time.h>

#define N 10000000
#define N_INIT 10000
#define N_CASES 4

bool a[N];
bool b[N];

int main(int argc, char* argv[argc + 1]) {

    size_t n = N_INIT;
    for (size_t i = 0; i < N_CASES; n *= 10, i++) {
        for (size_t j = 2; j < n; j++) {a[j] = true; b[j] = true;}

        // time for with guard
        clock_t toc = clock();
        for (size_t k = 2; k < n; k++) {
            if (a[k]) {
                for (size_t j = k; k*j < N; j++) a[k*j] = 0;
            }
        }
        clock_t tic = clock();
        double timeGuarded = (double)(tic - toc) / CLOCKS_PER_SEC;

        toc = clock();
        for (size_t k = 2; k < n; k++) {
            for (size_t j = k; k*j < N; j++) b[k*j] = 0;
        }
        tic = clock();
        double timeUnguarded = (double)(tic - toc) / CLOCKS_PER_SEC;

        printf("N: %zu, Time for guarded: %f, Time for unguarded: %f\n",
            n, timeGuarded, timeUnguarded);
        
        bool error_found = false;
        for (size_t k = 0; k < n; k++) {
            if (a[k] != b[k]) {
                printf("Mismatch found for k: %4zu\n", k);
                error_found = true;
                break;
            }
        }
        if (!error_found) {
            printf("Approaches agree\n");
        }
    }
    return 0;
}