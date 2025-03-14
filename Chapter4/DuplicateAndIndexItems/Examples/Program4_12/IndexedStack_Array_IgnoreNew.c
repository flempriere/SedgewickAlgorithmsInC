/**
 * @file Stack_idxIgnoreNew.c
 * @author Felix Lempriere
 * @brief Pushdown stack implementation assuming all items
 * are indices between 0 and maxN - 1. A seen array is used
 * to track which indices are in the stack.
 *
 * Duplicate items are ignored with a ignore-the-new policy.
 *
 * We update the example code to use the stack_v3 interface with
 * better error handling.
 *
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdint.h>
 #include <stdio.h>
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

/**
 * @brief largest valid index.
 * 
 */
 static size_t maxIdx;


 bool INDEXEDSTACKinit(size_t maxN) {

    s = malloc(maxN * sizeof(typeof(*s)));
    seen = calloc(maxN, sizeof(typeof(*seen)));
    if (s && seen) {
      N = 0;
      maxIdx = maxN - 1;
      return true;
    }
    INDEXEDSTACKerror("failed to initialise stack");
    return false;
 }

 size_t INDEXEDSTACKcount(void) {
    return N;
 }

 bool INDEXEDSTACKpush(size_t idx) {
    if (idx > maxIdx) {
      INDEXEDSTACKerror("attempted to push invalid index");
      return false;
    }
    if (seen[idx]) return true;
    s[N++] = idx;
    seen[idx] = true;
    return true;
 }

 size_t INDEXEDSTACKpop(void) {
   if (!N) {
      INDEXEDSTACKerror("failed to pop, stack empty");
      return SIZE_MAX;
   }
    N--;
    seen[s[N]] = false;
    return s[N];
 }

 void INDEXEDSTACKerror(char *msg) {
   fprintf(stderr, "Error: %s\n", msg);
 }
