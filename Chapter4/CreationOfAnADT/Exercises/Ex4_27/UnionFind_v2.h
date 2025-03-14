/**
 * @file UnionFind_v2.h
 * @author Felix Lempriere
 * @brief Interface for a Union Find ADT comprising three operations,
 * initialise, find and union.
 *
 * Extends the original UnionFind ADT with a UFUnionFind function call
 * that performs a find and union in one call to the ADT.
 *
 * @version 2.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #pragma once
 
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

/**
 * @brief Combines the effects of a Union and a Find
 * into one client call.
 * 
 * @param i first node to connect
 * @param j second node to connect
 *
 * @return size_t index of canonical node if already connected else
 * @return NOT_FOUND.
 */
size_t UFunionFind(size_t i, size_t j);