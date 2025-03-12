/**
 * @file testQueue.c
 * @author Felix Lempriere
 * @brief A simple program for testing a Queue implementation.
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
 #include "../Program4_9/Queue.h"
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
    QUEUEinit(test_size);

    printf("Testing that initialised Queue is empty\n");
    assert(QUEUEempty());

    for (Item i = 0; i < test_size; i++) {
        QUEUEput(i);
    }
    printf("Testing non-empty queue shows as non-empty\n");
    assert(!QUEUEempty());
    
    printf("Asserting FIFO order obeyed\n");
    for (size_t i = 0; i < test_size - 1; i++) {
        assert(QUEUEget() == (Item) i);
    }
    printf("Check FIFO is preserved for interleaved get and put\n");
    QUEUEput(test_size);
    for (Item i = test_size - 1; i < test_size + 1; i++) {
        assert(QUEUEget() == i); 
    }
    printf("All tests passed\n");
    return EXIT_SUCCESS; 
 }