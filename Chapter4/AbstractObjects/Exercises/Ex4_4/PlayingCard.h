
/* Interface for a playing card 

    Supports a Joker that can be either no suit, red, black or any suit 
*/

/*TODO: Use c23 underlying types to convert card suit enum to unsigned
underlying type.*/
#pragma once
/**
 * @brief enum for card value, 
 * supports JOKERS
 */
typedef enum {PLAYINGCARD_JOKER, PLAYINGCARD_ACE, PLAYINGCARD_TWO, PLAYINGCARD_THREE, PLAYINGCARD_FOUR, PLAYINGCARD_FIVE, PLAYINGCARD_SIX, PLAYINGCARD_SEVEN,
    PLAYINGCARD_EIGHT, PLAYINGCARD_NINE, PLAYINGCARD_TEN, PLAYINGCARD_JACK, PLAYINGCARD_QUEEN, PLAYINGCARD_KING} e_PLAYINGCARDValue; /*joker set to 0, so
    other cards indices line up with their traditional points value */
/**
 * @brief enum for suit,
 * supports cards that can be multisuit.
 * 
 */
typedef enum {
    PLAYINGCARD_NONE = 0x0u,
    PLAYINGCARD_HEART = 0x01u,
    PLAYINGCARD_DIAMOND = (PLAYINGCARD_HEART << 1),
    PLAYINGCARD_RED = (PLAYINGCARD_HEART | PLAYINGCARD_DIAMOND),
    PLAYINGCARD_CLUB = (PLAYINGCARD_DIAMOND << 1),
    PLAYINGCARD_SPADE = (PLAYINGCARD_CLUB << 1),
    PLAYINGCARD_BLACK = (PLAYINGCARD_CLUB | PLAYINGCARD_SPADE),
    PLAYINGCARD_ALL = (PLAYINGCARD_RED | PLAYINGCARD_BLACK)
} e_PLAYINGCARDSuit;

typedef struct {
    e_PLAYINGCARDValue val;
    e_PLAYINGCARDSuit suit;
} PlayingCard;

