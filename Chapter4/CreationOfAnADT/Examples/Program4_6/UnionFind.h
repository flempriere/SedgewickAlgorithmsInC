/**
 * @file UnionFind.h
 * @author Felix Lempriere
 * @brief Interface for a Union Find ADT comprising three operations,
 * initialise, find and union.
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
  #include <stddef.h>
  #include <stdint.h>

  #define NOT_FOUND SIZE_MAX

 /**
  * @brief Initialise a new UF ADT of with size elements.
  * 
  * @param size number of elements in the union find.
  * 
  */
void UFinit(size_t size);

/**
 * @brief Find if two nodes are connected and return the canonical 
 * representative if they are.
 * 
 * @param i first node
 * @param j second node
 * @return size_t index of the canonical node if connected else
 * @return NOT_FOUND if not found.
 */
size_t UFfind(size_t i, size_t j);

/**
 * @brief Connect nodes i and j.
 * 
 * @param i first node to connect.
 * @param j second node to connect.
 */
void UFunion(size_t i, size_t j);