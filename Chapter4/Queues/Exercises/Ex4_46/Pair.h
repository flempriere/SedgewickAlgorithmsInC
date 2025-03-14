/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Item interface for a pair of numbers.
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #pragma once

 #include <stddef.h>
 #include <stdio.h>

 typedef struct Pair {
    size_t i;
    size_t j;
 } Pair;

/**
 * @brief Checks two pairs for equality.
 *
 * @param A first pair to compare
 * @param B second pair to compare
 * 
 * @return true if equal else
 * @return false.
 */
 #define PAIReq(A, B) (((A).i == (B).i) && ((A).j == (B).j))


 /**
  * @brief Print out a pair.
  *
  * @param A, pair to print. 
  */
 #define PAIRshow(A) (printf("%zu %zu", (A).i, (A).j))

/**
 * @brief Makes an returns a new Pair as a stack object
 * 
 * @param i first element of the pair
 * @param j second element of the pair
 * @return Pair 
 */
 static inline Pair PAIRmake(size_t i, size_t j) {
   return (Pair) {.i = i, .j = j};
 }