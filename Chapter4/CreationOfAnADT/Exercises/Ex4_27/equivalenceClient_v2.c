/**
 * @file equivalenceClient_v2.c
 * @author Felix Lempriere
 * @brief Modification of Program 4.7 to take advantage of
 * UFunionFind  function added to the UnionFind ADT.
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "UnionFind_v2.h"

 int main(int argc, char* argv[argc]) {

    if (!(argc == 2)) {
        fprintf(stderr, "Error: usage %s N\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t p, q;
    size_t N = (size_t) strtoull(argv[1], nullptr, 0);
    if (!N) {
        fprintf(stderr, "N must be > 0\n");
        return EXIT_FAILURE;
    }

    UFinit(N);
    while (scanf("%zu %zu", &p, &q) == 2) {
        if (UFunionFind(p, q) == NOT_FOUND) {
            printf(" %zu %zu\n", p, q);
        }
    }
    return EXIT_SUCCESS;    
 }