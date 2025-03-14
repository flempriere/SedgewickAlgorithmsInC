/**
 * @file Deck.h
 * @author Felix Lempriere
 * @brief Interface for a Deck of Playing Cards.
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #pragma once
 #include "PlayingCard.h"

 /**
  * @brief Number of standard cards in a complete deck
  * 
  */
 #define STANDARD_CARDS_IN_DECK 52

 /**
  * @brief Number of jokers in a deck.
  * 
  */
 #define JOKERS_IN_DECK 2

 /**
  * @brief Initialises and shuffles a standard deck of playing cards,
  * with optional inclusion of jokers.
  * 
  * @param useJokers boolean flag to indicate if jokers are to be used.
  * true means include jokers.
  * @return true if deck successfully initialised, else
  * @return false 
  */
bool DECKinit(bool useJokers);

/**
 * @brief Adds all dealt cards back into the deck.
 *
 * @return true if success else,
 * @return false.
 */
 bool DECKrestore(void);

/**
 * @brief Deals nCards cards from the deck.
 *
 * The client is responsible for freeing the returned array
 * after use.
 * 
 * @param nCards 
 * @return playing_card* array containing the dealt cards if successful, else
 * @return nullptr on fail. 
 */
 PlayingCard* DECKdeal(size_t nCards);









