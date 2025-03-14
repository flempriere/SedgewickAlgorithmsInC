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
 * @brief Pointer to next free index in the dealt array.
 * 
 */
 static size_t dealtp;

 /**
  * @brief array of suit values so we can iterate over them.
  * 
  */
 static e_PLAYINGCARDSuit suits[] = {PLAYINGCARD_HEART, PLAYINGCARD_DIAMOND, PLAYINGCARD_SPADE, PLAYINGCARD_CLUB};



 bool DECKinit(bool useJokers) {
    //include room for jokers initially unless we 
    if(!RANDOMQUEUEinit(STANDARD_CARDS_IN_DECK + JOKERS_IN_DECK)) {
        return false;
    }
    //populate the standard deck.
    for (size_t i = 0; i < 4; i++) {
        e_PLAYINGCARDSuit suit =suits[i];
        for (e_PLAYINGCARDValue value = PLAYINGCARD_ACE; value <= PLAYINGCARD_KING; value++) {
            if(!RANDOMQUEUEput((PlayingCard) {.suit = suit, .val=value})) {
                return false;
            }
        }
    }
    //if using jokers, add them to the deck.
    if (useJokers) {
        if(!RANDOMQUEUEput((PlayingCard) {.suit = PLAYINGCARD_RED, .val = PLAYINGCARD_JOKER})) return false;
        if(!RANDOMQUEUEput((PlayingCard) {.suit = PLAYINGCARD_BLACK, .val = PLAYINGCARD_JOKER})) return false;
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
            dealt[dealtp++] = hand[idx]; //store dealt card.
            free(hand);
            return nullptr;
        }
    }
    return hand;
 }



 