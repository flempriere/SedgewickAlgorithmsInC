/*
Exercise 1-20:
    - Modify Weighted Union to use the 'height' of the tree
    - Compare the timing of this with Program 1.3
*/


#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Input pair values must be less than N
 * 
 */
#define N 10000u

/**
 * @brief size of the input buffer for fgets.
 * 
 */
 #define MAXLINE 100u


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
 * @brief Compares the max of two elements
 * 
 * @param x first item to be compared
 * @param y second item to be compared
 * 
 * @warning x and y must support the > operator.
 * @return 
 */
#define MAX(x,y) ((x) > (y)) ? (x) : (y) 

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
    size_t p, q;
    size_t n_acc = 0; //number of array accesses. 
    char line[MAXLINE];

    for (size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 0;
    }
    while (fgets(line, sizeof(line), stdin) && 
    sscanf(line, "%zu %zu", &p, &q) == 2) {

        size_t i, j;
        for (i = p; n_acc++, i != id[i]; i = id[i], n_acc++);
        for (j = q; n_acc++, j != id[j]; j = id[j], n_acc++);

        if (i == j) continue;

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] = MAX(sz[i], sz[j] + 1);
        n_acc++;
        printf(" %zu %zu\n", p, q);
        printArr(N, id);

    }
    printf("Number of id array accesses: %zu\n", n_acc);

    if (!feof(stdin)) {
        fprintf(stderr, "Error occured during read\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

void printArr(size_t len, size_t a[len])
{
    for (size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
