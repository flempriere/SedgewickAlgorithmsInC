/**
 * @file UnionFind_struct.c
 * @author Felix Lempriere
 * @brief Implementation of the Ex4.28 UnionFind interface including
 * the additional UFcountConnectedNodes but utilising an array of structs rather
 * than a pair of arrays.
 *
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stddef.h>
 #include <stdlib.h>
 #include "../Ex4_28/UnionFind_v3.h"

 typedef struct UFunionFindNode {
    size_t idx;
    size_t size;
 } UFunionFindNode;

 static UFunionFindNode* forest;


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

    forest = malloc(size * sizeof(typeof(*forest)));

    for (size_t i = 0; i < size; i++) {
        forest[i].idx = i;
        forest[i].size = 1;
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
    for (i = x; i != forest[i].idx; i = forest[i].idx) {
        forest[i].idx = forest[forest[i].idx].idx;
    }
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
    if (forest[p].size < forest[q].size) UFswap(&p, &q);
    forest[q].idx = p;
    forest[p].size += forest[q].size;
    return;
 }

 size_t UFunionFind(size_t i, size_t j) {
    size_t p = UFfindCanonical(i);
    size_t q = UFfindCanonical(j);
    if (p == q) return p;
    if (forest[p].size < forest[q].size) UFswap(&p, &q);
    forest[q].idx = p;
    forest[p].size += forest[q].size;
    return NOT_FOUND;
 }

 size_t UFcountConnectedNodes(size_t i) {
    return forest[UFfindCanonical(i)].size;
 }