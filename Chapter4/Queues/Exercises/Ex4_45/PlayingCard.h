
/* Interface for a playing card 

    Supports a Joker that can be either no suit, red, black or any suit 
*/

/*TODO: Use c23 underlying types to convert card suit enum to unsigned
underlying type.*/
#pragma once

#include <stdint.h>
#include <stdio.h>

/**
 * @brief enum for card value, 
 * supports JOKERS
 */
typedef enum : uint8_t {JOKER, ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
    EIGHT, NINE, TEN, JACK, QUEEN, KING} e_cardValue; /*joker set to 0, so
    other cards indices line up with their traditional points value */
/**
 * @brief enum for suit,
 * supports cards that can be multisuit.
 * 
 */
typedef enum : uint8_t {
    NONE = 0x0u,
    HEART = 0x01u,
    DIAMOND = (HEART << 1),
    RED = (HEART | DIAMOND),
    CLUB = (DIAMOND << 1),
    SPADE = (CLUB << 1),
    BLACK = (CLUB | SPADE),
    ALL = (RED | BLACK)
} e_cardSuit;

/**
 * @brief Struct for a playing card containing a value and a suit.
 * 
 */
typedef struct {
    e_cardValue val;
    e_cardSuit suit;
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
static char* PLAYINGCARDsuitSymbol[ALL+1] = {
    [HEART] = "\u2661",
    [DIAMOND] = "\u2662",
    [RED] = "R",
    [SPADE] = "\u2664",
    [CLUB] = "\u2667",
    [BLACK] = "B"
};

/**
 * @brief Symbol table to map value to print output
 * 
 */
static char* PLAYINGCARDvalSymbol[KING+1] = {
    [JOKER] = "\u272A",
    [ACE] = "A",
    [TWO] = "2",
    [THREE] = "3",
    [FOUR] = "4",
    [FIVE] = "5",
    [SIX] = "6",
    [SEVEN] = "7",
    [EIGHT] = "8",
    [NINE] = "9",
    [TEN] = "10",
    [JACK] = "J",
    [QUEEN] = "Q",
    [KING] = "K"
};

/**
 * @brief Prints a representation of a playing card.
 * 
 */
static inline void PLAYINGCARDshow(PlayingCard A) {
    printf("%s%s",
        PLAYINGCARDvalSymbol[(A).val], PLAYINGCARDsuitSymbol[(A).suit]);
}
