/*
This function reverses a list, returning a pointer to the final Node,
which is now the new head Node. The first Node link is now a nullptr.
*/
#include "MacroLibrary/DefaultCalloc.h"
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Key type for Node structure
 *
 */
typedef size_t key;

/**
 * @brief LinkedList Node
 * consisting of a @key
 * and next Node.
 *
 * @see key
 */
typedef struct Node Node;
struct Node {
    key k;
    Node* next;
};

/**
 * @brief Builds a list of N nodes labeled 1 through to N and attaches
 * them to the Node h which acts as the head.
 *
 * @param h head to build the list onto.
 * @param N Number of nodes to build.
 */
void build_list(Node h[static 1], size_t const n);

/**
 * @brief Prints out the linked list and optionally frees the nodes as
 * it goes. Assumes a linear linked list with non-dummy head.
 *
 * @param h head of the list
 * @param freeList flags if the list should be freed after printing.
 */
void print_list(Node* h, bool const freeList);

/**
 * @brief Reverse a linkedList. This modifies
 * the linkedlist in place.
 *
 * @param x head of the linked list to reverse
 * @return Node*, head of the reversed list.
 */
Node* reverse(Node* const x);

/**
 * @brief Demonstrates linkedList reversal
 *
 * @return EXIT_SUCCESS on successful completion
 */
int main(int argc, char* argv[argc + 1]) {
    constexpr size_t N = 10u;

    Node* const head = CALLOC_FAILS_EXIT(*head);
    *head = CAST(Node){ .k = 0, .next = nullptr };
    build_list(head, N);
    print_list(head, false);

    // demonstrate reversed Node and free.
    print_list(reverse(head), true);

    return EXIT_SUCCESS;
}

Node* reverse(Node* const x) {
    register Node* y = x;          //
    register Node* r = nullptr;    // reversed list

    while (y != nullptr) {
        register Node* t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    return r;
}

void build_list(Node h[static 1], size_t const n) {
    for (register size_t i = 1; i < n; i++) {
        register Node* const t = CALLOC_FAILS_EXIT(*t);
        t->next = nullptr;
        t->k = i;
        h->next = t;
        h = h->next;
    }
}

void print_list(Node* h, bool const freeList) {
    while (h != nullptr) {
        printf("%zu->", h->k);
        register Node* h_nxt = h->next;
        if (freeList) { free(h); }
        h = h_nxt;
    }
    printf("X\n");
}