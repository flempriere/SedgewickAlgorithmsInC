/**
 * @file pokerDealer.c
 * @author Felix Lempriere
 * @brief Using the Deck interface deals out N poker hands.
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
 #include "Deck.h"
 #include "PlayingCard.h"

/**
 * @brief Number of cards in a hand to deal.
 * 
 */
 #define CARDS_IN_HAND 5u


/**
 * @brief Deals N poker hands using the Deck interface.
 * 
 * @param argc number of arguments
 * @param argv[1] number of hands to deal. 
 * @return EXIT_SUCCESS on success, else
 * @return EXIT_FAILURE
 */
 int main(int argc, char* argv[argc]) {
     if (argc != 2) {
         fprintf(stderr, "Error: Usage %s N\n", argv[0]);
     }

     //set up the deck and number of hands
     size_t N = strtoull(argv[1], nullptr, 0);

     srand(time(nullptr));
     if (!DECKinit(false)) return EXIT_FAILURE;

     for (size_t i = 1; i <= N; i++) {
        PlayingCard* hand = DECKdeal(CARDS_IN_HAND);
        if (!hand) {
            fprintf(stderr, "Error, failed to get hand %zu\n", i);
            return EXIT_FAILURE;
        }
        printf("Hand %zu: \t", i);
        for (size_t i = 0; i < CARDS_IN_HAND; i++) {
            PLAYINGCARDshow(hand[i]);
            printf("\t");
        }
        free(hand);
        printf("\n");
     }
     return EXIT_SUCCESS;
  }