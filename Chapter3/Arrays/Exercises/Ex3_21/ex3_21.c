/*
Exercise 3.21

Modify program 3.7 to generate a heads with probability lambda/N
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * @brief Probability of heads factor.
 * P(HEADS) = LAMBDA/N
 * 
 */
#define LAMBDA 10

/**
 * @brief performs a coin toss
 * 
 * @return true if result is heads,
 * @return false if result is tails
 */
bool heads(double lambda, size_t N);

/**
 * @brief Performs M experiments each consisting
 * of N coin tosses with probability of heads
 * LAMBDA/N and counts the number of heads
 * in each run.
 * 
 * The final distribution is plotted.
 * 
 * @param argc[1] N 
 * @param argc[2] M
 * @return EXIT_SUCCESS if completes, else
 * @return EXIT_FAILURE if there is an error
 * 
 * @see LAMBDA
 */
int main(int argc, char* argv[argc + 1]) {
    
    if (argc != 3) {
        fprintf(stderr, "Error: requires arguments N and M\n");
        return EXIT_FAILURE;
    }
    size_t N = strtoull(argv[1], NULL, 0);
    size_t M = strtoull(argv[2], NULL, 0);
    double p = LAMBDA;
    srand(time(nullptr));

    size_t* f = malloc((N+1)*sizeof(typeof_unqual(*f)));
    for (size_t j = 0; j <= N; j++) f[j] = 0;

    for (size_t i = 0; i < M; i++) {
        size_t cnt = 0;
        for (size_t j = 0; j <= N; j++) {
            if (heads(p, N)) cnt++;
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

bool heads(double lambda, size_t N) {
    return rand() < (RAND_MAX * (lambda)/N);
}
