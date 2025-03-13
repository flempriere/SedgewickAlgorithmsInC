/**
 * @file lottery.c
 * @author Felix Lempriere
 * @brief Picks out a lottery number of placing the numbers
 * 1 through 99 inclusive on a random Queue then printing the result
 * of removing five of them.
 *
 * @version 0.1
 * @date 2025-03-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include "../../../AbstractObjects/Examples/intItem/Item.h"
 #include "../Ex4_42/RandomQueue.h"

 /**
  * @brief Smallest lottery number.
  * 
  */
 #define MIN_NUM 1
 /**
  * @brief Largest lottery number (inclusive)
  * 
  */
 #define MAX_NUM 99

 /**
  * @brief Number of numbers to pull for lottery number.
  * 
  */
 #define N_NUMS 5


 /**
  * @brief Generates a lottery number by placing the numbers between
  * MIN_NUM and MAX_NUM (inclusive) on a random queue then calling
  * get N_NUM times.
  * 
  * @param argc 
  * @param argv 
  * @return int 
  */
 int main(int argc, char* argv[argc]) {

    //seed rng for random queue
    srand(time(nullptr));
    RANDOMQUEUEinit((MAX_NUM - MIN_NUM) + 1);

    //populate
    for (int i = MIN_NUM; i <= MAX_NUM; i++) {
        if(!RANDOMQUEUEput(i)) return EXIT_FAILURE;
    }

    printf("Lottery number: ");
    Item dest;
    for (size_t i = 0; i < N_NUMS; i++) {
        if (!RANDOMQUEUEget(&dest)) {
            return EXIT_FAILURE;
        }
        printf("%d ", dest);
    }
    printf("\n");
    return EXIT_SUCCESS;
 }