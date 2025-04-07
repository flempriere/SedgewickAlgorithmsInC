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

/**
 * @brief enum for card value,
 * supports JOKERS
 *
 * @details
 */
typedef enum : uint8_t {
    PLAYINGCARD_JOKER,
    PLAYINGCARD_ACE,
    PLAYINGCARD_TWO,
    PLAYINGCARD_THREE,
    PLAYINGCARD_FOUR,
    PLAYINGCARD_FIVE,
    PLAYINGCARD_SIX,
    PLAYINGCARD_SEVEN,
    PLAYINGCARD_EIGHT,
    PLAYINGCARD_NINE,
    PLAYINGCARD_TEN,
    PLAYINGCARD_JACK,
    PLAYINGCARD_QUEEN,
    PLAYINGCARD_KING
} e_PLAYINGCARDValue;

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