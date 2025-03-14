/**
 * @file Deck.c
 * @author Felix Lempriere
 * @brief Implementation of the Deck interface using a Random Queue.
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 
 #include <stdlib.h>
 #include "PlayingCard.h"
 #include "Deck.h"
 #include "RandomQueue.h"

/**
 * @brief Tracks which cards have been dealt.
 * 
 */
 static PlayingCard dealt[STANDARD_CARDS_IN_DECK + JOKERS_IN_DECK];

 /**
  * @brief array of suit values so we can iterate over them.
  * 
  */
 static e_cardSuit suits[] = {HEART, DIAMOND, SPADE, CLUB};

 static size_t dealtp;

 bool DECKinit(bool useJokers) {
    //include room for jokers initially unless we 
    if(!RANDOMQUEUEinit(STANDARD_CARDS_IN_DECK + JOKERS_IN_DECK)) {
        return false;
    }
    //populate the standard deck.
    for (size_t i = 0; i < 4; i++) {
        e_cardSuit suit =suits[i];
        for (e_cardValue value = ACE; value <= KING; value++) {
            if(!RANDOMQUEUEput((PlayingCard) {.suit = suit, .val=value})) {
                return false;
            }
        }
    }
    if (useJokers) {
        if(!RANDOMQUEUEput((PlayingCard) {.suit = RED, .val = JOKER})) return false;
        if(!RANDOMQUEUEput((PlayingCard) {.suit = BLACK, .val = JOKER})) return false;
    }
    return true;
 }


 bool DECKrestore(void) {
    while (dealtp) {
        if(!RANDOMQUEUEput(dealt[--dealtp])) return false;
    }
    return true;
 }

 PlayingCard* DECKdeal(size_t nCards) {

    PlayingCard* hand = malloc(nCards * sizeof(typeof(*hand)));
    if (!hand) {
        return nullptr;
    }
    for (size_t idx = 0; idx < nCards; idx++) {
        if (!RANDOMQUEUEget(hand + idx)) {
            free(hand);
            return nullptr;
        }
    }
    return hand;
 }



 