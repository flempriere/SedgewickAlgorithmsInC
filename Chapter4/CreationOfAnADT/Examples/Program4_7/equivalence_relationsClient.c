/**
 * @file equivalence_relationsClient.c
 * @author Felix Lempriere
 * @brief A simple use of the Union Find ADT interface
 * to solve the connectivity problem.
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include "../Program4_6/UnionFind.h"

 int main(int argc, char* argv[argc]) {

    if (!(argc == 2)) {
        fprintf(stderr, "Error: usage %s N\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t p, q;
    size_t N = (size_t) strtoull(argv[1], nullptr, 0);
    if (!N) {
        fprintf(stderr, "N must be >= 0\n");
        return EXIT_FAILURE;
    }

    UFinit(N);
    while (scanf("%zu %zu", &p, &q) == 2) {
        if (UFfind(p, q) == NOT_FOUND) {
            UFunion(p, q);
            printf(" %zu %zu\n", p, q);
        }
    }
    return EXIT_SUCCESS;    
 }