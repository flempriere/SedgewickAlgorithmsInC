/**
 * @file stackArray.c
 * @brief When there are N items in the stack this
 * implementation keeps then in s[0] ... s[N-1]; in order
 * from least recently inserted to most recently inserted.
 * 
 * The top of the stack (the position where the next item to
 * be pushed will go) is s[N]. The client program passes the
 * maximum number of items expected on the stack as the argument
 * to STACKInit, which allocates an array of that size, but this
 * code does not check for errors such as pushing onto a
 * full stack (or popping an empty one).
 * 
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdlib.h>
#include "Item.h"
#include "stack.h"

/**
 * @brief private array representing the stack
 * 
 */
static Item* s;

/**
 * @brief private variable representing the stack head
 * 
 */
static int N;


void STACKinit(size_t capacity) {
    s = malloc(capacity * sizeof(typeof(*s)));
    N = 0;
};

bool STACKempty() {
    return (N > 0);
}

void STACKpush(Item i) {
    s[N++] = i;
}

Item STACKpop() {
    return s[--N];
}

