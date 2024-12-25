/**
 * @file ex3_71.c
 * @author Felix Lempriere
 * @brief Modifies and shows the result of assuming
 * a directed graph representation for Program 3.18
 * and Program 3.19
 * 
 * @version 0.1
 * @date 2024-12-24
 * 
 * @copyright Copyright (c) 2024
 * 
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

/**
 * @brief Node structure
 * containing a key value
 * and a next pointer.
 * 
 */
typedef struct node node;
struct node {
    size_t v;
    node* nxt;
};
/**
 * @brief builds a new node, the
 * user is responsible for handling
 * the memory.
 * 
 * @param v node key value
 * @param  nxt next pointer for node
 * @return node*
 */
node* NEW(size_t v, node* nxt);

/**
 * @brief Builds and outputs a directed adjacency
 * matrix representation and direct adjacency list
 * of a graph.
 * 
 * @return EXIT_SUCCESS on successful exit, else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {

    //setup adjacency matrix
    int adjM[V][V];
    
    for (size_t i = 0; i < V; i++) {
        for (size_t j = 0; j < V; j++) {
            adjM[i][j] = 0;
        }
    } 
    for (size_t i = 0; i < V; i++) adjM[i][i] = 1;

    //setup adjacency list
    node* adjL[V];
    
    for (size_t i = 0; i < V; i++) adjL[i] = nullptr;

    while(true) {
        char buf[bufSize];
        size_t i, j;
        if (!fgets(buf, sizeof(buf), stdin)) break;
        if(sscanf(buf, "%zu %zu\n", &i, &j) == 2) {
            adjM[i][j] = 1;
            adjL[i] = NEW(j, adjL[i]);
        } else {
            fprintf(stderr, "Input should be of the form x y\n");
            return EXIT_FAILURE;
        }
    }

    //print adjacency matrix
    printf("Directed adjacency matrix: \n");
    for (size_t i = 0; i < V; i++) {
        for (size_t j = 0; j < V; j++) {
            printf(" %d ", adjM[i][j]);
        }
        printf("\n");
    }

    //print adjacency list
    printf("Directed adjacency list: \n");
    for (size_t i = 0; i < V; i++) {
        printf("vertex %zu adjacent to: ", i);
        for (node* cur = adjL[i]; cur; cur = cur->nxt) {
            printf(" %zu ", cur->v);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}

node* NEW(size_t v, node* nxt) {
    node* new = malloc(sizeof(typeof(*new)));
    new->v = v;
    new->nxt = nxt;
    return new;
}
