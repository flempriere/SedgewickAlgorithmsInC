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

#include "../../../../MacroLibrary/DefaultCalloc.h"
#include "../../../../MacroLibrary/Random.h"

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
 * @brief Builds a Linked list consisting of N nodes onto the head node h.
 * Each key value is randomly generated from 0 up to MAX_KEY exclusive.
 *
 * @param h
 * @param N
 */
void build_list(node* h, size_t n);

/**
 * @brief Prints out the linked list and optionally
 *
 * @param h head of the list
 * @param freeList flags if the list should be freed after printing.
 */
void print_list(node* h, bool freeList);

/**
 * @brief insertion sort the linked list with dummy head @in, and attach
 * the sorted list to the dummy head *out.
 *
 * @param in dummy head of the input unsorted list.
 * @param out dummy head to attach the sorted output list to.
 */
void insertion_sort(node* in, node* out);

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
    build_list(&head_i, N);

    printf("=== Unsorted Input ===\n");
    print_list(head_i.next, false);

    // insertion sort output
    insertion_sort(&head_i, &head_o);
    // print outcome and cleanup
    printf("=== Sorted Input ===\n");
    print_list(head_o.next, true);

    return EXIT_SUCCESS;
}

void build_list(node* h, size_t n) {
    for (register size_t i = 0; i < n; i++) {
        h->next = CALLOC_FAILS_EXIT(*h);
        h = h->next;
        h->next = nullptr;

        h->k = RAND_NUM(MAX_KEY);
    }
}

void print_list(node* h, bool freeList) {
    while (h != nullptr) {
        printf("%zu->", h->k);
        register node* h_nxt = h->next;
        if (freeList) { free(h); }
        h = h_nxt;
    }
    printf("X\n");
}

void insertion_sort(node* in, node* out) {
    register node* u = nullptr;
    out->next = nullptr;
    for (register node* t = in->next; t != nullptr; t = u) {
        u = t->next;
        register node* x = nullptr;
        for (x = out; x->next != nullptr; x = x->next) {
            if (x->next->k > t->k) break;
        }
        t->next = x->next;
        x->next = t;
    }
}