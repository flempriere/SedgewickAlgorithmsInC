/*
Exercise 3.20

Modify program 3.7 to generate a heads with probability p and then test the
results for p = 1/6.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * @brief Probability of heads
 * 
 */
#define P_HEADS 1.0/6.0

/**
 * @brief performs a coin toss
 * 
 * @return true if result is heads,
 * @return false if result is tails
 */
bool heads(double p);

/**
 * @brief Performs M experiments each consisting
 * of N coin tosses with probability of heads
 * P_HEADS and counts the number of heads
 * in each run.
 * 
 * The final distribution is plotted.
 * 
 * @param argc[1] N 
 * @param argc[2] M
 * @return EXIT_SUCCESS if completes, else
 * @return EXIT_FAILURE if there is an error
 * 
 * @see P_HEADS
 */
int main(int argc, char* argv[argc + 1]) {
    
    if (argc != 3) {
        fprintf(stderr, "Error: requires arguments N and M\n");
        return EXIT_FAILURE;
    }
    size_t N = strtoull(argv[1], NULL, 0);
    size_t M = strtoull(argv[2], NULL, 0);
    srand(time(nullptr));
    double p = P_HEADS;

    size_t* f = malloc((N+1)*sizeof(typeof_unqual(*f)));
    for (size_t j = 0; j <= N; j++) f[j] = 0;

    for (size_t i = 0; i < M; i++) {
        size_t cnt = 0;
        for (size_t j = 0; j <= N; j++) {
            if (heads(p)) cnt++;
        }
        f[cnt]++;
    }
    for (size_t j = 0; j <= N; j++) {
        printf("%2zu ", j);
        for (size_t i = 0; i < f[j]; i += 10) printf("*");
        printf("\n");
    }
    return EXIT_SUCCESS;
}

bool heads(double p) {
    return rand() < (RAND_MAX * p);
}
