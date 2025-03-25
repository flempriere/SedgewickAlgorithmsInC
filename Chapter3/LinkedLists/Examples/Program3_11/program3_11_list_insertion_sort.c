/*
Program 3.11 List Insertion Sort

Generates N random integers between 0 and 999, builds a linked list with one
number per node and then rearranges the list so that the numbers appear in
order when traversed.

To sort, two lists arre maintained an unsorted input, and a sorted output. At
each step a node is removed from the input, and inserted into position in
the output.

We use dummy head nodes that point to the first true node of the list.
 */

#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Key type for node structure
 *
 */
typedef size_t key;
/**
 * @brief LinkedList node
 * consisting of a @key
 * and next node.
 *
 * @see key
 */
typedef struct node node;
struct node {
    key k;
    node* next;
};

/**
 * @brief Dummy head for the input (unsorted) linkedList
 */
node head_i;
/**
 * @brief Dummy head the for the output (sorted) linkedList
 *
 */
node head_o;

/**
 * @brief Number of random numbers to generate
 *
 */
constexpr size_t N = 10u;
/**
 * @brief Exclusive upper bound on valid key values
 *
 */
constexpr key MAX_KEY = 1000u;

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
    register node* a = &head_i;
    register node* t = a;
    RAND_SEED_TIME;

    for (register size_t i = 0; i < N; i++) {
        t->next = calloc(1, SIZEOF_VARTYPE(*t));
        t = t->next;
        t->next = nullptr;

        t->k = RAND_NUM(MAX_KEY);
    }
    for (register node const* h = a->next; h != nullptr; h = h->next) {
        printf("%zu->", h->k);
    }
    printf("X - unsorted input\n");

    // insertion sort output
    register node* b = &head_o;
    register node* u = nullptr;

    b->next = nullptr;
    for (t = a->next; t != nullptr; t = u) {
        u = t->next;
        register node* x = nullptr;
        for (x = b; x->next != nullptr; x = x->next) {
            if (x->next->k > t->k) break;
        }
        t->next = x->next;
        x->next = t;
    }
    // print outcome and cleanup
    for (register node* h = b->next; h != nullptr;) {
        printf("%zu->", h->k);
        register node* tmp = h->next;
        free(h);
        h = tmp;
    }

    printf("X - sorted output\n");
    return EXIT_SUCCESS;
}