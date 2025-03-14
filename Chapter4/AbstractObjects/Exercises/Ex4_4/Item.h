/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Provides a generic Item interface wrapping
 * around the Playing Card structure defined in
 * PlayingCard.h
 * @version 0.1
 * @date 2024-12-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "PlayingCard.h"
#include <stdio.h>

/**
 * @brief typedef to treat playing card
 * as a generic item
 * 
 */
typedef PlayingCard Item;

/**
 * @brief Test playing card equality
 * 
 */
#define eq(A, B) ((A.val == B.val) && (A.suit == B.suit))

/**
 * @brief Symbol table to map suit to print output
 * 
 */
static char* suitSymbol[ALL+1] = {
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
static char* valSymbol[KING+1] = {
    [JOKER] = "J",
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

#define ITEMshow(A) printf("%s%s", valSymbol[A.val], suitSymbol[A.suit])
