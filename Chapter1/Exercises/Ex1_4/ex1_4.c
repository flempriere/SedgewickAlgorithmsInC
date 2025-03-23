/*
Exercise 1-4:
    - show the state of the id array at each stage of reading from
    sample_data.dat.
    - count the total number of array accesses (overall and per edge)
    - Using Quick Find algorithm
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Input pair values must be less than N
 *
 */
constexpr size_t N = 10u;

/**
 * @brief size of the input buffer for fgets.
 *
 */
constexpr size_t MAXLINE = 100u;

/**
 * @brief Prints the first @len elements of an array a
 *
 * @param len size_t type, length of the array
 * @param a size_t type, must be of size at least len.
 */
void printArr(size_t len, size_t a[len]);

/**
 * @brief Reads input pairs `p,q < N` from
 * standard input and performs a union operation. If
 * `p` and `q` where not already connected they are
 * printed to output.
 *
 * Prints the contents of the id[] array after each
 * unions.
 *
 * Prints the number of array accesses for each input
 * pair and for the entire program execution.
 *
 * @exception if p or q is not less than N the input
 * pair is ignored
 *
 * @return EXIT_SUCCESS on exit.
 *
 */
int main(void) {
    size_t p;
    size_t q;
    size_t id[N];
    register size_t tot_accesses = 0;
    char line[MAXLINE];

    for (register size_t i = 0; i < N; i++) id[i] = i;

    while (fgets(line, sizeof(line), stdin) &&
           sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;    // bounds checking

        register size_t n_accesses = 0;
        if (id[p] == id[q]) {
            n_accesses += 2;
            goto updateArrayAccesses;
        }

        register size_t t = id[p];
        for (register size_t i = 0; i < N; i++) {
            n_accesses += 1;
            if (id[i] == t) {
                id[i] = id[q];
                n_accesses += 2;
            }
        }
        printf(" %zu %zu\n", p, q);
    updateArrayAccesses:
        printArr(N, id);
        printf("array acceses for (%zu, %zu): %zu\n", p, q, n_accesses);
        tot_accesses += n_accesses;
    }
    printf("Total array acceses: %zu\n", tot_accesses);
    if (!feof(stdin)) {
        fprintf(stderr, "Error occured during read\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void printArr(size_t len, size_t a[len]) {
    for (register size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
