/**
 * @file ex3_73.c
 * @brief Modifies Program 3.19 to read in the number of vertices as a
 * command line argument and dynamically allocate the row-list array.
 * @version 0.1
 * @date 2024-12-24
 */

#include <stdio.h>
#include <stdlib.h>

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

    if (argc != 2) {
        fprintf(stderr, "Error: Usage ./%s V\n", argv[0]);
        return EXIT_FAILURE;
    }
    size_t V = strtoull(argv[1], nullptr, 0);
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

