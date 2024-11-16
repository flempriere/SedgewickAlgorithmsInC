/* Interface for a playing card 

    Supports a Joker that can be either no suit, red, black or any suit 
*/

/*TODO: Use c23 underlying types to convert card suit enum to unsigned
underlying type.*/

typedef enum {JOKER, ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
    EIGHT, NINE, TEN, JACK, QUEEN, KING} e_cardValue; /*joker set to 0, so
    other cards indices line up with their traditional points value */

typedef enum {
    NONE = 0x0u,
    HEART = 0x01u,
    DIAMOND = (HEART << 1),
    RED = (HEART | DIAMOND),
    CLUB = (DIAMOND << 1),
    SPADE = (CLUB << 1),
    BLACK = (CLUB | SPADE),
    ALL = (RED | BLACK)
} e_cardSuit;

typedef struct {
    e_cardValue val;
    e_cardSuit suit;
} playing_card;