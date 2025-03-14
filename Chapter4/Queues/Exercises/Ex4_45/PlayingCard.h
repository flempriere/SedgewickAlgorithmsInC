/**
 * @file PlayingCard.h
 * @author Felix Lempriere
 * @brief Interface for an individual Playing Card following the Item interface
 * idioms.
 *
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include <stdint.h>
#include <stdio.h>

/**
 * @brief enum for card value, 
 * supports JOKERS
 */
typedef enum : uint8_t {PLAYINGCARD_JOKER, PLAYINGCARD_ACE, PLAYINGCARD_TWO, 
    PLAYINGCARD_THREE, PLAYINGCARD_FOUR, PLAYINGCARD_FIVE, PLAYINGCARD_SIX,
    PLAYINGCARD_SEVEN, PLAYINGCARD_EIGHT, PLAYINGCARD_NINE, PLAYINGCARD_TEN,
    PLAYINGCARD_JACK, PLAYINGCARD_QUEEN, PLAYINGCARD_KING} e_PLAYINGCARDValue; /*joker set to 0, so
    other cards indices line up with their traditional points value */
/**
 * @brief enum for suit,
 * supports cards that can be multisuit.
 * 
 */
typedef enum : uint8_t {
    PLAYINGCARD_NONE = 0x0u,
    PLAYINGCARD_HEART = 0x01u,
    PLAYINGCARD_DIAMOND = (PLAYINGCARD_HEART << 1),
    PLAYINGCARD_RED = (PLAYINGCARD_HEART | PLAYINGCARD_DIAMOND),
    PLAYINGCARD_CLUB = (PLAYINGCARD_DIAMOND << 1),
    PLAYINGCARD_SPADE = (PLAYINGCARD_CLUB << 1),
    PLAYINGCARD_BLACK = (PLAYINGCARD_CLUB | PLAYINGCARD_SPADE),
    PLAYINGCARD_ALL = (PLAYINGCARD_RED | PLAYINGCARD_BLACK)
} e_PLAYINGCARDSuit;

/**
 * @brief Struct for a playing card containing a value and a suit.
 * 
 */
typedef struct {
    e_PLAYINGCARDValue val;
    e_PLAYINGCARDSuit suit;
} PlayingCard;


/**
 * @brief Test playing card equality
 * 
 */
#define PLAYINGCARDeq(A,B) (((A).val == (B).val) && ((A).suit == (B).suit))

 /**
  * @brief Symbol table to map suit to print output
  * 
  */
static char* PLAYINGCARDsuitSymbol[PLAYINGCARD_ALL+1] = {
    [PLAYINGCARD_HEART] = "\u2661",
    [PLAYINGCARD_DIAMOND] = "\u2662",
    [PLAYINGCARD_RED] = "R",
    [PLAYINGCARD_SPADE] = "\u2664",
    [PLAYINGCARD_CLUB] = "\u2667",
    [PLAYINGCARD_BLACK] = "B"
};

/**
 * @brief Symbol table to map value to print output
 * 
 */
static char* PLAYINGCARDvalSymbol[PLAYINGCARD_KING+1] = {
    [PLAYINGCARD_JOKER] = "\u272A",
    [PLAYINGCARD_ACE] = "A",
    [PLAYINGCARD_TWO] = "2",
    [PLAYINGCARD_THREE] = "3",
    [PLAYINGCARD_FOUR] = "4",
    [PLAYINGCARD_FIVE] = "5",
    [PLAYINGCARD_SIX] = "6",
    [PLAYINGCARD_SEVEN] = "7",
    [PLAYINGCARD_EIGHT] = "8",
    [PLAYINGCARD_NINE] = "9",
    [PLAYINGCARD_TEN] = "10",
    [PLAYINGCARD_JACK] = "J",
    [PLAYINGCARD_QUEEN] = "Q",
    [PLAYINGCARD_KING] = "K"
};

/**
 * @brief Prints a representation of a playing card.
 * 
 */
static inline void PLAYINGCARDshow(PlayingCard A) {
    printf("%s%s",
        PLAYINGCARDvalSymbol[(A).val], PLAYINGCARDsuitSymbol[(A).suit]);
}
