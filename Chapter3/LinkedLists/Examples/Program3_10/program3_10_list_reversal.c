/*
This function reverses a list, returning a pointer to the final node,
which is now the new head node. The first node link is now a nullptr.
*/
#include "../../../../MacroLibrary/DefaultCalloc.h"

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
 * @brief Builds a list of N nodes labeled 1 through to N.
 * 
 * @param h 
 * @param N 
 */
void build_list(node* h, size_t N);

/**
 * @brief Prints out the linked list and optionally 
 * 
 * @param h head of the list
 * @param freeList flags if the list should be freed after printing.
 */
void print_list(node* h, bool freeList);

/**
 * @brief Reverse a linkedList. This modifies
 * the linkedlist in place.
 *
 * @param x head of the linked list to reverse
 * @return node*, head of the reversed list.
 */
node* reverse(node* const x);

/**
 * @brief Demonstrates linkedList reversal
 *
 * @return EXIT_SUCCESS on successful completion
 */
int main(int argc, char* argv[argc + 1]) {
    constexpr size_t N = 10u;

    register node* const head = CALLOC_FAILS_EXIT(*head);
    head->k = 0;
    build_list(head, N);
    print_list(head, false);

    // demonstrate reversed node and free.
    print_list(reverse(head), true);

    return EXIT_SUCCESS;
}

node* reverse(node* const x) {
    register node* y = x;          //
    register node* r = nullptr;    // reversed list

    while (y != nullptr) {
        register node* t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    return r;
}

void build_list(node* h, size_t n) {
    for (register size_t i = 1; i < n; i++) {
        register node* const t = CALLOC_FAILS_EXIT(*t);
        t->next = nullptr;
        t->k = i;
        h->next = t;
        h = h->next;
    }
}

void print_list(node* h, bool freeList) {
    while(h != nullptr) {
        printf("%zu->", h->k);
        register node* h_nxt = h->next;
        if (freeList) {
            free(h);
        }
        h = h_nxt;
    }
    printf("X\n"); 
}