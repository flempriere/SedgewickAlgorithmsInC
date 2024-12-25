/**
 * @file ex3_75.c
 * @author Felix Lempriere
 * @brief Repeats Exercise 3.74 but for an adjacency list
 * @version 0.1
 * @date 2024-12-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * @brief Number of vertices in generated graph
 * 
 */
#define V 10

/**
 * @brief probability of including an edge in
 * the random graph.
 * 
 */
#define P_EDGE 0.5

/**
 * @brief size of the intermediate input
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
 * @param G adjacency list
 * @return size_t 
 */
size_t numberOfTwoPaths(size_t a, size_t b, size_t v, node* G[v]);

/**
 * @brief tests numberOfTwoPaths by generating a random graph
 * by choosing to include any edge with @P_EDGE.
 * 
 * @return EXIT_SUCCESS on successful exit, else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {

    node* adj[V];
    for (size_t i = 0; i < V; i++) adj[i] = nullptr;

    srand(time(nullptr)); 

    //randomly generate graph
    for (size_t i = (V-1); i < V; i--) {
        for (size_t j = (V-1); j < V; j--) {
            if (i == j) continue;
            if ((double) rand() / (double) RAND_MAX <= P_EDGE) {
                adj[i] = NEW(j, adj[i]);
            }
        }
    }

    //print out the graph
    printf("Random directed adjacency matrix: \n");
    for (size_t i = 0; i < V; i++) {
        printf("%zu has edges to: ", i);
        for (node* v = adj[i]; v; v = v->nxt) {
            printf("%zu%s", v->v, (v->nxt) ? ", " : ".\n");
        }
    }
    size_t a = rand() % V;
    size_t b = rand() % V;

    size_t nTwoPaths = numberOfTwoPaths(a, b, V, adj);
    printf("Number of two paths from %zu to %zu: %zu\n",
        a, b, nTwoPaths);

    return EXIT_SUCCESS;
}

size_t numberOfTwoPaths(size_t a, size_t b, size_t v, node* G[v]) {
    size_t count = 0;
    for (size_t i = 0; i < V; i++) {
        node* cur = nullptr;
        for (cur = G[a]; cur && cur->v != i; cur = cur->nxt);
        if (!cur) continue; //didn't find a->i
        cur = nullptr;
        for (cur = G[i]; cur && cur->v != b; cur = cur->nxt);
        if (!cur) continue; //didn't find i->b
        count++;
    }
    return count;
}

node* NEW(size_t v, node* nxt) {
    node* new = malloc(sizeof(typeof(*new)));
    new->v = v;
    new->nxt = nxt;
    return new;
}