/**
 * @file testDoubleStack.c
 * @author Felix Lempriere
 * @brief Performs some simple tests on the Double Stack
 * ADT defined by doubleStack.h
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 /**
 * @file testStack_v3.c
 * @author Felix Lempriere
 * @brief Small file to test stack_v3 implementation.
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
 #include "doubleStack.h"
 #include "Item.h"

 /**
  * @brief Tests 
  * 
  * @param argc number of args
  * @param argv arguments
  * @return EXIT_SUCCESS on successful exit.
  */
 int main(int argc, char* argv[argc]) {

    size_t test_size = 3;
    printf("Testing initialisation\n");
    assert(STACKinit(test_size));

    printf("===Testing the lower stack works as a normal stack===\n");
    printf("Testing push with sufficient space\n");
    for (size_t i = 1; i <= test_size; i++) {
        assert(STACKlowerPush(i));
    }
    printf("Testing push to a full stack fails\n");
    assert(!STACKlowerPush(test_size+1));

    printf("Testing stack count\n");
    assert(STACKlowerCount() == test_size); //assert can fill

    printf("Testing stack pop\n");
    Item dest; 
    assert(STACKlowerPop(&dest) && dest == test_size);
    assert(STACKlowerPop(&dest) && dest  == (test_size - 1));
    assert(STACKlowerPop(&dest) && dest == (test_size -2));
    printf("Assert stack is empty\n");
    assert(STACKlowerCount() == 0);
    printf("Testing pop from empty stack fails\n");
    assert(!STACKlowerPop(&dest));

    printf("===All lower stack tests passed\n===");

    printf("===Testing the upper stack works as a normal stack===\n");
    printf("Testing push with sufficient space\n");
    for (size_t i = 1; i <= test_size; i++) {
        assert(STACKupperPush(i));
    }
    printf("Testing push to a full stack fails\n");
    assert(!STACKupperPush(test_size+1));

    printf("Testing stack count\n");
    assert(STACKupperCount() == test_size); //assert can fill

    printf("Testing stack pop\n");
    assert(STACKupperPop(&dest) && dest == test_size);
    assert(STACKupperPop(&dest) && dest  == (test_size - 1));
    assert(STACKupperPop(&dest) && dest == (test_size -2));
    printf("Assert stack is empty\n");
    assert(STACKupperCount() == 0);
    printf("Testing pop from empty stack fails\n");
    assert(!STACKupperPop(&dest));

    printf("===All upper stack tests passed===\n");


    printf("=== Testing use of upper and lower stack together===\n");
    printf("Testing that you can fill the stack with both\n");
    for (size_t i = 1; i <= test_size; i++) {
        if (i % 2) {
            assert(STACKlowerPush(i));
        }
        else {
            assert(STACKupperPush(i));
        }
    }
    printf("Checking can't push to a full stack\n");
    assert(!STACKlowerPush(test_size+1));
    assert(!STACKupperPush(test_size + 1));

    printf("Mixed tests passed\n");
    printf("All Tests passed\n");
    return EXIT_SUCCESS;
 }