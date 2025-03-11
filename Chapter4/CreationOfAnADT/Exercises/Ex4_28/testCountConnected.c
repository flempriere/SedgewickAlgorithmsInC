/**
 * @file testCountConnected.c
 * @author FElix Lempriere
 * @brief Simple Test script to test UFcountConnectedNodes implementation.
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <assert.h>
 #include "UnionFind_v3.h"

 int main(int argc, char* argv[argc]) {

    size_t test_cases = 3;
    UFinit(test_cases);
    printf("Check that all initial sizes are 1\n");
    for (size_t i = 0; i < test_cases; i++) {
        assert(UFcountConnectedNodes(i) == 1);
    }
    printf("Check that after union both unioned nodes sizes increase\n");
    UFunionFind(0, 1);
    assert(UFcountConnectedNodes(0) == UFcountConnectedNodes(1));
    printf("Check that size increase is correct\n");
    assert(UFcountConnectedNodes(0) == 2 );

    printf("Check that untouched node's size does not change\n");
    assert(UFcountConnectedNodes(2) == 1);

    printf("Check that unioning two sets of unequal size works as intended\n");
    UFunionFind(1, 2);
    assert(UFcountConnectedNodes(1) == UFcountConnectedNodes(2));
    assert(UFcountConnectedNodes(1) == 3);
    assert(UFcountConnectedNodes(0) == 3);

    printf("Check that attempting to union already merged sets does not"
        " modify size\n");
    size_t sz_before = UFcountConnectedNodes(0);
    UFunionFind(0, 1);
    assert(UFcountConnectedNodes(0) == sz_before);
    assert(UFcountConnectedNodes(0) == UFcountConnectedNodes(1));
    assert(UFcountConnectedNodes(1) == UFcountConnectedNodes(2));

    printf("All tests passed\n"); 
    return EXIT_SUCCESS;
 }