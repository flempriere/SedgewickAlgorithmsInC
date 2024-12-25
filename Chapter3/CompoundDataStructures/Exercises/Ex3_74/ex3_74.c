/**
 * @file ex3_74.c
 * @author Felix Lempriere
 * @brief Uses an adjacency matrix of a graph to compute the number
 * of vertices c, such that for a given pair of vertices a,b there
 * is an edge from a to c and c to b.
 * @version 0.1
 * @date 2024-12-25
 * 
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/**
 * @brief Number of vertices in the graph
 */
#define V 10ULL

/**
 * @brief Probability of edge existing in the
 * random graph
 * 
 */
#define P_EDGE 0.5

/**
 * @brief Returns the number of length two paths from
 * the vertex a to the vertex b using the adjacency matrix
 * for the graph G.
 * 
 * Equivalently returns the number of vertices c such that
 * there is an edge from a to c and c to b.
 * 
 * @param a source vertex
 * @param b dest vertex
 * @param v total number of vertices
 * @param G adjacency matrix
 * @return size_t 
 */
size_t numberOfTwoPaths(size_t a, size_t b, size_t v, bool* G[V]);

/**
 * @brief Allocate a 2d array
 * 
 * @param row number of rows
 * @param col number of columns
 * @return bool** pointer to matrix stored in m[row][col].
 */
bool** malloc2d(size_t row, size_t col);

/**
 * @brief Tests numberOfTwoPaths by randomly generating a
 * graph by including each (non-self-referential) edge with
 * probability @P_EDGE, then randomly generating two vertices
 * and testing the result.
 * 
 * @return EXIT_SUCCESS on completion.
 */
int main(int argc, char* argv[argc]) {

    bool** adj = malloc2d(V, V);
    for (size_t i = 0; i < V; i++) adj[i][i] = !adj[i][i]; //turn on diagonals

    srand(time(nullptr)); 

    //randomly generate graph
    for (size_t i = 0; i < V; i++) {
        for (size_t j = 0; j < V; j++) {
            if (i == j) continue;
            adj[i][j] = (((double) rand()) / ((double) RAND_MAX) <= P_EDGE);
        }
    }

    //print out the graph
    printf("Random directed adjacency matrix: \n");
    for (size_t i = 0; i < V; i++) {
        for (size_t j = 0; j < V; j++) {
            printf(" %d ", adj[i][j]);
        }
        printf("\n");
    }
    size_t a = rand() % V;
    size_t b = rand() % V;

    size_t nTwoPaths = numberOfTwoPaths(a, b, V, adj);
    printf("Number of two paths from %zu to %zu: %zu\n",
        a, b, nTwoPaths);

    return EXIT_SUCCESS;
}

size_t numberOfTwoPaths(size_t a, size_t b, size_t v, bool* G[V]) {

    size_t count = 0;
    for (size_t c = 0; c < V; c++) {
        count += G[a][c] * G[c][b]; //since only true * true = true
    }
    return count;
}


bool** malloc2d(size_t row, size_t col) {
    bool** a = malloc(row * sizeof(typeof(*a)));
    while(--row < SIZE_MAX) a[row] = malloc(col * sizeof(typeof(**a)));
    return a;
}