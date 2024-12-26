/**
 * @file ex4_4.c
 * @author Felix Lempriere
 * @brief Simple file to demonstrate the use of Item.h
 * as an interface to playing card.h
 * @version 0.1
 * @date 2024-12-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

int main(int argc, char* argv[argc]) {

    Item c1 = {.suit = RED, .val = JOKER};
    Item c2 = {.suit = HEART, .val = KING};
    Item c3 = {.suit = SPADE, .val = THREE};

    printf("Card 1: ");
    ITEMshow(c1);
    printf("\n");

    printf("Card 2: ");
    ITEMshow(c2);
    printf("\n");

    printf("Card 3: ");
    ITEMshow(c3);
    printf("\n");

    return EXIT_SUCCESS;
}