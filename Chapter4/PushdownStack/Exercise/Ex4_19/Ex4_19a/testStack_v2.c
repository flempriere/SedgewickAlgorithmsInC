/**
 * @file testStack_v2.c
 * @author Felix Lempriere
 * @brief Small file to test stack_v2 implementation.
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
 #include "stack_v2.h"


 /**
  * @brief Tests 
  * 
  * @param argc number of args
  * @param argv arguments
  * @return EXIT_SUCCESS on successful exit.
  */
 int main(void) {

    size_t test_size = 3;
    STACKinit(test_size);

    for (size_t i = 1; i <= test_size; i++) {
        STACKpush(i);
    }
    assert(STACKcount() == test_size); //assert can fill
    assert(STACKpop() == (test_size));
    assert(STACKpop() == (test_size - 1));
    assert(STACKcount() == (test_size -2));

    printf("All tests passed\n");
    return EXIT_SUCCESS;
 }