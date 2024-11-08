/*
Exercise 1-16 and 1-17
    - Implement full path compression
    - show that state of the id array at each stage of reading from 
    sample_data.dat.
    - count the total number of array accesses (overall and for each edge)
*/


#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Input pair values must be less than N
 * 
 */
#define N 16

/**
 * @brief swap's x and y
 * 
 * @param x first item to be swapped
 * @param y second item to be swapped
 * 
 * Uses C23 typeof_unqual operator to
 * determine types of @x and @y for
 * temporary variable _t.
 */
#define SWAP(x,y) do {  \
    typeof_unqual(x) _t = x;      \
    x = y;              \
    y = _t;             \
} while(0)              \

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
 * @exception if p or q is not less than N the input
 * pair is ignored
 * 
 * @return EXIT_SUCCESS on exit.
 * 
 */
int main(int argc, char *argv[argc + 1]) {
    size_t id[N];
    size_t sz[N];
    size_t p, q, tot_access = 0;

    for (size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    while (scanf("%zu %zu\n", &p , &q) == 2) {
        if (p >= N || q >= N) continue;
        size_t i, j;
        size_t n_access = 0;
        //find the root
        for (i = p; n_access += 1, i != id[i]; i = id[i], n_access += 1);

        //traverse tree and compress
        while(p != i) {
            size_t np = id[p];
            n_access += 2;
            id[p] = i;
            p = np;
        }
        //repeat for other value
        for (j = q; n_access += 1, j != id[j]; j = id[j], n_access += 1);

        while (q != j) {
            size_t nq = id[q];
            n_access += 2;
            id[q] = j;
            q = nq;
        }
        if (i == j) {goto updateArrayAccesses;}

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];
        n_access += 1;
        printf(" %zu %zu\n", p, q);
        printArr(N, id);
updateArrayAccesses: 
        printf("array acceses for (%zu, %zu): %zu\n", 
            p, q, n_access);
        tot_access += n_access;
    }
    printf("id array accesses: %zu\n", tot_access);
    return EXIT_SUCCESS; 
}

void printArr(size_t len, size_t a[len])
{
    for (size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
