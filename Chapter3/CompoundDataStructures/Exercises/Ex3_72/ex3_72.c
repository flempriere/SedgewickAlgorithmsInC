/**
 * @file ex3_72.c
 * @author Felix Lempriere
 * @brief Modification of Program 3.18 to take the number
 * of vertices as a command line argument and dynamically
 * allocate the result.
 * @version 0.1
 * @date 2024-12-24
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**
 * @brief Allocate a 2d array
 * 
 * @param row number of rows
 * @param col number of columns
 * @return int** pointer to matrix stored in m[row][col].
 */
int** malloc2d(size_t row, size_t col);
/**
 * @brief Size of a the intermediate input
 * buffer
 * 
 */
#define bufSize 10

/**
 * @brief Builds and outputs an adjacency
 * matrix representation of a graph.
 * 
 * @return EXIT_SUCCESS on successful exit, else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {

    if (!(argc == 2)) {
        fprintf(stderr, "Error: Usage ./%s V\n", argv[0]);
        return EXIT_FAILURE; 
    }
    size_t V = strtoull(argv[1], nullptr, 0);
    int** adj = malloc2d(V, V);

    
    for (size_t i = 0; i < V; i++) {
        for (size_t j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    } 
    for (size_t i = 0; i < V; i++) adj[i][i] = 1;


    while(true) {
        char buf[bufSize];
        size_t i, j;
        if (!fgets(buf, sizeof(buf), stdin)) break;
        if(sscanf(buf, "%zu %zu\n", &i, &j) == 2) {
            adj[i][j] = 1;
            adj[j][i] = 1;
        } else {
            fprintf(stderr, "Input should be of the form x y\n");
            return EXIT_FAILURE;
        }
    }
    //print adjacency matrix
    for (size_t i = 0; i < V; i++) {
        for (size_t j = 0; j < V; j++) {
            printf(" %d ", adj[i][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}


int** malloc2d(size_t row, size_t col) {
    int** a = malloc(row * sizeof(typeof(*a)));
    while(--row < SIZE_MAX) a[row] = malloc(col * sizeof(typeof(**a)));
    return a;
}