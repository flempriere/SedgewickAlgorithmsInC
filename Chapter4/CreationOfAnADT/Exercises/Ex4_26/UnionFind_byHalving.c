/**
 * @file UnionFind.c
 * @author Felix Lempriere
 * @brief Implementation of the Program 4.6 UnionFind
 * interface, improves on Program 4.8 by implementing path compression
 * by halving on performing find.
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stddef.h>
 #include <stdlib.h>
 #include "../../Examples/Program4_6/UnionFind.h"

 /**
  * @brief parent array, id[p] is the parent of p.
  * if p has no parent, then id[p] == p.
  */
 static size_t* id;
 /**
  * @brief size array. sz[i] is the number of elements
  * in the set rooted at i.
  */
 static size_t* sz;

 /**
  * @brief swap two indices
  * 
  * @param i pointer to first idx to swap
  * @param j pointer to second idx to swap
  */
 static inline void UFswap(size_t* i, size_t* j) {
    size_t t = *i;
    *i = *j;
    *j = t;
    return;
 }

 void UFinit(size_t size) {
    id = malloc(size * sizeof(typeof(*id)));
    sz = malloc(size * sizeof(typeof(*sz)));

    for (size_t i = 0; i < size; i++) {
        id[i] = i;
        sz[i] = 1;
    }
 }

 /**
  * @brief Finds the can
  * 
  * @param x 
  * @return size_t 
  */
 static size_t UFfindCanonical(size_t x) {
    size_t i;
    for (i = x; i != id[i]; i = id[i]) {id[i] = id[id[i]];}
    return i;
 }

 size_t UFfind(size_t i, size_t j) {
    size_t idx = UFfindCanonical(i); //get canonical id
    return (idx == UFfindCanonical(j)) ? j : NOT_FOUND;
 }

 void UFunion(size_t i, size_t j) {
    size_t p = UFfindCanonical(i);
    size_t q = UFfindCanonical(j);

    if (p == q) return;
    if (sz[p] < sz[q]) UFswap(&p, &q);
    id[q] = p;
    sz[p] += sz[q];
    return;
 }