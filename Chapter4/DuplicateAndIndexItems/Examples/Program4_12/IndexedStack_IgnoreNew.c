/**
 * @file Stack_idxIgnoreNew.c
 * @author Felix Lempriere
 * @brief Pushdown stack implementation assuming all items
 * are indices between 0 and maxN - 1. A seen array is used
 * to track which indices are in the stack.
 *
 * Duplicate items are ignored with a ignore-the-new policy.
 *
 * This version performs no error checking.
 *
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdlib.h>
 #include "IndexedStack.h"


/**
 * @brief Array containing the stack.
 * 
 */
 static size_t* s;

/**
 * @brief Array indicating which elements are on
 * the stack.
 * 
 */
 static bool* seen;

 /**
  * @brief index of the next free stack element.
  * 
  */
 static size_t N;


 void STACKinit(size_t maxN) {

    s = malloc(maxN * sizeof(typeof(*s)));
    //initialise seen array to 0;
    seen = calloc(maxN, sizeof(typeof(*seen)));
    N = 0;

 }

 bool STACKempty(void) {
    return (!N);
 }

 void STACKpush(size_t item) {
    if (seen[item]) return;
    s[N++] = item;
    seen[item] = true;
 }

 size_t STACKpop(void) {
    N--;
    seen[s[N]] = false;
    return s[N];
 }

