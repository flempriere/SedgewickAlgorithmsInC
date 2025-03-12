/**
 * @file testQueue_v2.c
 * @author Felix Lempriere
 * @brief A simple program for testing a Queue_v2 interface implementation.
 * @version 0.1
 * @date 2025-03-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdlib.h>
 #include <stddef.h>
 #include <stdio.h>
 #include <assert.h>
 #include "Queue_v2.h"
 #include "../../../AbstractObjects/Examples/intItem/Item.h"
 
 /**
  * @brief Simple test program for Queue implementation. Compile with
  * the chosen implementation and run the test. Checks that empty() works
  * as expected and that the FIFO get order is correct.
  * 
  * @param argc 
  * @param argv 
  * @return EXIT_SUCCESS if all tests passed.
  */
 int main(int argc, char* argv[argc]) {

    size_t test_size = 3;
    printf("Testing Queue initalised\n");
    assert(QUEUEinit(test_size));

    printf("Testing that initialised Queue is empty\n");
    assert(QUEUEempty());

    printf("Testing filling to capacity works\n");
    for (Item i = 0; i < test_size; i++) {
        assert(QUEUEput(i));
    }
    printf("Testing non-empty queue shows as non-empty\n");
    assert(!QUEUEempty());

    printf("Testing put on full queue fails\n");
    assert(!QUEUEput(test_size));

    printf("Asserting FIFO order obeyed\n");
    for (Item i = 0; i < test_size - 1; i++) {
        Item val;
        assert(QUEUEget(&val));
        assert(val == i);
    }
    printf("Check FIFO is preserved for interleaved get and put\n");
    assert(QUEUEput(test_size));
    for (size_t i = test_size - 1; i < test_size + 1; i++) {
        Item val;
        assert(QUEUEget(&val));
        assert(val == i);
    }
    Item discard;
    printf("Assert get from empty queue fails\n");
    assert(QUEUEempty() && !QUEUEget(&discard));

    printf("All tests passed\n");
    return EXIT_SUCCESS; 
 }