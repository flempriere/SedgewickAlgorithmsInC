/**
 * @file adjacencyList.c
 * @brief This program reads a set of edges that define an
 * undirected graph and builds an adjacency list representation
 * for the graph, adding a node containing j to the a[i] list, if there is
 * an edge from i to j.
 * 
 * The program assumes that the number of vertices V is a compile
 * time constant. Otherwise, it would need to dynamically
 * allocate the adjacency list (see Ex. 3.72)
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
 * @brief Builds and outputs an adjacency
 * list representation of a graph.
 * 
 * @return EXIT_SUCCESS on successful exit, else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    node* adj[V];
    
    for (size_t i = 0; i < V; i++) adj[i] = nullptr;

    while(true) {
        char buf[bufSize];
        size_t i, j;
        if (!fgets(buf, sizeof(buf), stdin)) break;
        if(sscanf(buf, "%zu %zu\n", &i, &j) == 2) {
            adj[i] = NEW(j, adj[i]);
            adj[j] = NEW(i, adj[j]);
        } else {
            fprintf(stderr, "Input should be of the form x y\n");
            return EXIT_FAILURE;
        }
    }
    //print adjacency list
    for (size_t i = 0; i < V; i++) {
        printf("vertex %zu adjacent to: ", i);
        for (node* cur = adj[i]; cur; cur = cur->nxt) {
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

