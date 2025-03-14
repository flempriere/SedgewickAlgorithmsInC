/**
 * @file ex4_3.c
 * @author Felix Lempriere
 * @brief Sample code demonstrating the modified Item.h
 * from the examples to include Itemshow.
 * @version 0.1
 * @date 2024-12-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

/**
 * @brief Demonstrates the updates interfaces for
 * Item.h with both a numeric item and a stringtype item.
 * 
 * @return EXIT_SUCCESS on completion.
 */
int main(int argc, char* argv[argc]) {

    numericItem a = 0;
    numericItem b = 1;

    printf("Testing numericItem equality, expected: true, result: %s\n",
        NUMBEReq(a,a) ? "true" : "false");
    printf("Testing numericItem equality, expected: false, result: %s\n",
        NUMBEReq(a,b) ? "true" : "false");
    
    printf("Testing numericItemshow. Expected: 0, result: "); NUMBERitemShow(a);
    printf("\n");

    //testing strItem
    strItem c = "word";
    strItem d = "wordle";

    printf("Testing strItem equality, expected: true, result: %s\n",
        STRINGeq(c,c) ? "true" : "false");
    printf("Testing strItem equality, expected: false, result: %s\n",
        STRINGeq(c,d) ? "true" : "false");
    
    printf("Testing strItemshow. Expected: word, result: "); STRINGitemShow(c);
    printf("\n");

    return EXIT_SUCCESS;
}