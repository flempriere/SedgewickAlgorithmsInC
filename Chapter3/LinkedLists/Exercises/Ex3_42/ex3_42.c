/*
Exercise 3.42

Implements a version of program 3.11 that does not use
head nodes.
 */

#include "List/Node/Node.h"
#include "MacroLibrary/Random.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of random numbers to generate
 *
 */
constexpr size_t N = 10u;

/**
 * @brief Performs an insertion sort on the list pointed to by h.
 * Assuming a linear non-dummy head implementation.
 *
 * @param h
 * @return NODENode* head of the now sorted list.
 */
NODENode* insertion_sort(NODENode* h);
/**
 * @brief Generates an unsorted linked list on
 * N nodes with random integers from 0 up to MAX_KEY-1.
 *
 * The resulting list is then sorted to produce a
 * second sorted list.
 *
 * @return EXIT_SUCCESS
 *
 * @see N, @see MAX_KEY
 */
int main(int argc, char* argv[argc + 1]) {
    RAND_SEED_TIME;

    // generate the list
    register NODENode* head = NODEbuild_lin_list(N, NODEgen_key_rand);
    if (!head) return EXIT_FAILURE;

    printf("===unsorted input===\n");
    NODEprint_null_terminated_list(head);

    // perform insertion sort
    head = insertion_sort(head);
    printf("===sorted output===\n");
    NODEprint_null_terminated_list(head);

    NODEdelete_null_terminated_list(head);
    return EXIT_SUCCESS;
}

NODENode* insertion_sort(NODENode* h) {
    register NODENode* out = nullptr;
    for (register NODENode* t = h; t != nullptr; t = h) {
        h = t->next;
        if (!out) {
            out = t;
            out->next = nullptr;
        } else {
            if (out->k > t->k) {
                t->next = out;
                out = t;
            } else {
                register NODENode* x = out;
                for (; x->next != nullptr; x = x->next) {
                    if (x->next->k > t->k) break;
                }
                t->next = x->next;
                x->next = t;
            }
        }
    }
    return out;
}