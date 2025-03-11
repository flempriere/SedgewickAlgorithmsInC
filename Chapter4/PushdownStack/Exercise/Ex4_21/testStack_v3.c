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
 #include "stack_v3.h"
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

    printf("Testing push with sufficient space\n");
    for (size_t i = 1; i <= test_size; i++) {
        assert(STACKpush(i));
    }

    printf("Testing stack count\n");
    assert(STACKcount() == test_size); //assert can fill

    printf("Testing stack pop\n");
    Item dest; 
    assert(STACKpop(&dest) && dest == test_size );
    assert(STACKpop(&dest) && dest  == (test_size - 1));
    assert(STACKpop(&dest) && dest == (test_size -2));
    printf("Assert stack is empty\n");
    assert(STACKcount() == 0);
    printf("Testing pop from empty stack fails\n");
    assert(!STACKpop(&dest));

    printf("All tests passed\n");
    return EXIT_SUCCESS;
 }