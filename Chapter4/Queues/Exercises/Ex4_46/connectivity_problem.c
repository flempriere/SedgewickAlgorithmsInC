/**
 * @file connectivity_problem.c
 * @author Felix Lempriere
 * @brief Solves the connectivity problem by inserting all the pairs on
 * a random queue and then taking them from the queue, using the quick-find
 * weighted algorithm (Program 1.3).
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include "../../../CreationOfAnADT/Exercises/Ex4_28/UnionFind_v3.h"
 #include "Pair.h"
 #include "RandomQueue_Pair.h"


 /**
  * @brief Solves the connectivity problem by placing all pairs on
  * a random queue and then taking them from the queue, using the quick-find
  * weighted algorithm.
  * 
  * @param argc number of arguments
  * @param argv[1] number of in the network to connect.
  * 
  * @return EXIT_SUCCESS on success, else
  * @return EXIT_FALSE.
  */
 int main(int argc, char* argv[argc]) {

    if (argc != 2) {
        fprintf(stderr, "Error: usage %s N\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t p, q;
    size_t N = (size_t) strtoull(argv[1], nullptr, 0);
    srand(time(nullptr));
    RANDOMQUEUEinit(N*N);
    if (!N) {
        fprintf(stderr, "N must be > 0\n");
        return EXIT_FAILURE;
    }

    //put the pairs on a random queue
    UFinit(N);
    while (scanf("%zu %zu", &p, &q) == 2) {
        if(!RANDOMQUEUEput(PAIRmake(p, q))) return EXIT_FAILURE;
    }

    //randomly select and perform the connections.
    printf("Forming connections...\n");
    while (!RANDOMQUEUEempty()) {
        Pair p;
        if(!RANDOMQUEUEget(&p)) return EXIT_FAILURE;
        if(UFunionFind(p.i, p.j) == NOT_FOUND) {
            PAIRshow(p);
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
 }