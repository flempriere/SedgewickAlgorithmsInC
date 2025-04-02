/**
 * @file Node.h
 * @author Felix Lempriere
 * @brief Header file containing code fragments for a minimal linked list
 *
 * This only defines the basic structure and some simple helper functions.
 * Plus any repeated functions such as the josephus code.
 * @version 0.1
 * @date 2025-04-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include "MacroLibrary/DefaultCalloc.h"
#include "MacroLibrary/Random.h"
#include "MacroLibrary/TraceMacro.h"
#include "MacroLibrary/Utility.h"

#include <stddef.h>
#include <stdlib.h>

typedef struct Node NODENode;

typedef size_t NODEKey;

/**
 * @brief Simple Node structure consisting of a key value and a next pointer.
 *
 */
struct Node {
    NODEKey k;
    NODENode* next;
};

/**
 * @brief Exclusive upper bound on valid key values
 *
 */
constexpr unsigned int MAX_KEY = 100u;

/**
 * @brief Make a Node with key @k and next pointer set to @nxt and
 * return it. The caller is responsible for handling the memory.
 *
 * @param k
 * @param nxt
 * @return Node*
 */
static inline NODENode* NODEmake_node(NODEKey const k, NODENode* const nxt) {
    NODENode* t = DEFAULTCALLOC(*t);
    if (!t) return nullptr;
    *t = CAST(NODENode){ .k = k, .next = nxt };
    return t;
}

// Delete functions

/**
 * @brief Deletes a list pointed to by @h assuming a circular structure.
 *
 * @param h
 */
void NODEdelete_circular_list(NODENode* h) {
    if (!h) return;
    for (register NODENode* tmp = h->next; tmp != h;) {
        register NODENode* del = tmp;
        tmp = tmp->next;
        free(del);
    }
    free(h);
}

/**
 * @brief Deletes a list pointed to by @h assuming a null-terminated linear
 * structure.
 *
 * @param h
 */
void NODEdelete_null_terminated_list(NODENode* h) {
    while (h != nullptr) {
        register NODENode* tmp = h;
        h = h->next;
        free(tmp);
    }
}

// Print functions

/**
 * @brief Prints a list pointed to by @h assuming a circular structure.
 *
 * @param h
 */
void NODEprint_circular_list(NODENode const h[static 1]) {
    for (register NODENode* t = h->next; t != h; t = t->next) {
        printf("%zu->", t->k);
    }
    printf("%zu\n", h->k);
}

/**
 * @brief Prints a list pointed to be @h assuming it is nullptr-terminated.
 *
 * @param head
 */
void NODEprint_null_terminated_list(NODENode const* head) {
    for (; head != nullptr; head = head->next) { printf("%zu->", head->k); }
    printf("X\n");
}

// josephus functions

/**
 * @brief Calculates the result of the Josephus function on the list pointed to
 * by h, making m link hops before each elimination. The last key value is
 * returned and all nodes on the list are freed.
 *
 * @param h
 * @param m
 * @return Key
 */
NODEKey NODEcalculate_josephus(NODENode h[static 1], size_t const m) {
    while (h != h->next) {
        for (register NODEKey i = 1; i < m; i++) h = h->next;
        register NODENode* tmp = h->next;
        h->next = h->next->next;
        free(tmp);
    }
    NODEKey k = h->k;
    free(h);
    return k;
}

// build functions

/**
 * @brief Cleans up a partially constructed list if the build fails during
 * construction. Returns a nullptr
 *
 * @param h head of the partially constructed list.
 *
 * @return nullptr
 */
NODENode* NODEclean_failed_build(NODENode* h) {
    TRACE_VALUE("Destroying partially constructed list\n", h);
    NODEdelete_null_terminated_list(h);
    return nullptr;
}
/**
 * @brief The improved efficiency construction of the josephus list from
 * Exercise 3.28, but made more generic to work for any circular list.
 *
 * Returns either a node on the list on success or a nullptr.
 * @param n
 * @param gen_key key to generate function.
 * @return Node* A pointer to the last node inserted on the list on success,
 * else
 * @return nullptr.
 */
NODENode* NODEbuild_circular_list(size_t const n, NODEKey (*gen_key)(void)) {
    NODENode* t = NODEmake_node(gen_key(), nullptr);
    if (!t) return NODEclean_failed_build(t);
    register NODENode* x = t;

    for (register NODEKey i = 2; i <= n; i++) {
        x = (x->next = NODEmake_node(i, nullptr));
        if (!x) return NODEclean_failed_build(t);
    }
    x->next = t;
    return x;
}
/**
 * @brief Returns an array of n + 1 nodes, with randomly generated key values
 * joined to give a sequential linked list with a dummy head and nullptr
 * termination.
 *
 * If the allocation fails then a nullptr is returned.
 * @param n
 * @param gen_key function pointer to generate the keys
 * @remark The list is returned as one contiguous block of memory.
 * @return Node const* dummy head of the list on success, else
 * @return nullptr.
 */
NODENode* NODEbuild_lin_list_dummy_head(size_t const n,
                                        NODEKey (*gen_key)(void)) {
    NODENode* const nodes = DEFAULTCALLOC(n + 1, *nodes);
    if (!nodes) return nullptr;

    for (register size_t i = 1; i <= n; i++) {
        register size_t k = gen_key();
        nodes[i - 1].next = &nodes[i];
        nodes[i].k = k;
    }

    nodes[n].next = nullptr;
    return nodes;
}

/**
 * @brief Builds a linear linked list of @n nodes with nullptr termination
 * and no dummy head.
 * 
 * @param n 
 * @param gen_key 
 * @return NODENode* pointer to head of the list on successful build, else
 * @return nullptr.
 */
NODENode* NODEbuild_lin_list(size_t n, NODEKey (*gen_key)(void)) {
    register NODENode* h = nullptr;
    for (register size_t i = 0; i < n;
         i++) {    // handle case where list is initially empty
        h = NODEmake_node(gen_key(), h);
        if (!h) return NODEclean_failed_build(h);
    }
    return h;
}

// standard key gen functions

/**
 * @brief Generates key values by increasing the counter by one everytime a
 * key is generated.
 *
 * @return Key
 */
static inline NODEKey NODEgen_key_idx(void) {
    static NODEKey nxt_k = 0;
    return nxt_k++;
}

/**
 * @brief Generates key values by generating a random value up to @MAX_KEY
 * 
 * @return NODEKey 
 *
 * @see @MAX_KEY
 */
static inline NODEKey NODEgen_key_rand(void) { return RANDUINT(MAX_KEY); }