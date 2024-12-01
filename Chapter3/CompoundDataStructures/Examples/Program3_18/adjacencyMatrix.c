/**
 * @file ex3_18.c
 * @brief This program reads a set of edges that define an
 * undirected graph and builds an adjacency matrix representation
 * for the graph, setting a[i][j] and a[j][i] to 1, if there is
 * an edge from i to j or j to i in the graph, or to 0 if there
 * is no such edge.
 * 
 * The program assumes that the number of vertices V is a compile
 * time constant. Otherwise, it would need to dynamically
 * allocate the adjacency matrix (see Ex. 3.72)
 * @version 0.1
 * @date 2024-12-01
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of vertices in the graph
 */
#define V 10

/**
 * @brief Size of a the intermediate input
 * buffer
 * 
 */
#define bufSize 10

int main(int argc, char* argv[argc + 1]) {
    int adj[V][V];
    
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
        while(sscanf(buf, "%zu %zu\n", &i, &j) == 2) {
            adj[i][j] = 1;
            adj[j][i] = 1;
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