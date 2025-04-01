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
#include "../../../../../MacroLibrary/DefaultCalloc.h"
#include "../../../../../MacroLibrary/Utility.h"
#include "../../../../../MacroLibrary/Random.h"

#include <stdlib.h>
#include <stddef.h>

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
 * @brief Make a Node with key @k and next pointer set to @nxt and
 * return it. The caller is responsible for handling the memory.
 *
 * @param k
 * @param nxt
 * @return Node*
 */
static inline NODENode* NODEmake_node(NODEKey const k, NODENode* const nxt) {
    NODENode* t = CALLOC_FAILS_EXIT(*t);
    *t = CAST(NODENode){ .k = k, .next = nxt };
    return t;
}

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

/**
 * @brief Prints a list pointed to by @h assuming a circular structure.
 *
 * @param h
 */
void NODEprint_circular_list(NODENode const* h) {
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

/**
 * @brief The improved efficiency construction of the josephus list from
 * Exercise 3.28.
 *
 * @param n
 * @return Node*
 */
NODENode* NODEbuild_josephus_list(size_t const n) {
    NODENode* t = NODEmake_node(1, nullptr);
    register NODENode* x = t;

    for (register NODEKey i = 2; i <= n; i++) {
        x = (x->next = NODEmake_node(i, nullptr));
    }
    x->next = t;
    return x;
}

// linear linked lists

/**
 * @brief Returns an array of n + 1 nodes, with randomly generated key values
 * joined to give a sequential linked list with a dummy head and nullptr
 * termination.
 *
 * @param n
 * @param f function pointer to generate the keys
 * @return Node const* dummy head of the list.
 */
NODENode* NODEbuild_lin_list_dummy_head(size_t const n, NODEKey (*f)(void)) {
    NODENode* const nodes = CALLOC_FAILS_EXIT(n + 1, *nodes);

    for (register size_t i = 1; i <= n; i++) {
        register size_t k = f();
        nodes[i - 1].next = &nodes[i];
        nodes[i].k = k;
    }
    nodes[n].next = nullptr;
    return nodes;
}

// standard key gen functions

/**
 * @brief Generates key values by increasing the counter by one everytime a
 * key is generated.
 *
 * @return Key
 */
static inline NODEKey gen_key_idx(void) {
    static NODEKey nxt_k = 0;
    return nxt_k++;
}

static inline NODEKey gen_key_rand(void) {
    return RANDuint(RAND_MAX);
}