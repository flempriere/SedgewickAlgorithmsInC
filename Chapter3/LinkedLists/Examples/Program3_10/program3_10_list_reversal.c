/*
This function reverses a list, returning a pointer to the final node,
which is now the new head node. The first node link is now a nullptr.
*/
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
    constexpr size_t N = 10;
    register node* const head = calloc(1, SIZEOF_VARTYPE(*head));
    head->k = 0;
    register node* x = head;

    for (register size_t i = 1; i < N; i++) {
        register node* const t = calloc(1, SIZEOF_VARTYPE(*head));
        t->next = nullptr;
        t->k = i;
        x->next = t;
        x = x->next;
    }

    for (register node const* h = head; h != nullptr; h = h->next) {
        printf("%zu->", h->k);
    }
    printf("X\n");

    // demonstrate reversed node and free.
    for (register node* h = reverse(head); h != nullptr;) {
        printf("%zu->", h->k);
        register node* tmp = h->next;
        free(h);
        h = tmp;
    }
    printf("X\n");

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
