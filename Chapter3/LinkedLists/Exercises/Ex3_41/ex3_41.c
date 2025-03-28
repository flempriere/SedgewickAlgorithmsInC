/*
Exercise 3.41

This function reverses a list, returning a pointer to the final node,
which is now the new head node. The first node link is now a nullptr.

Uses a dummy head representation.
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
 * @brief Print out a linked list starting at
 * the given node.
 *
 * @param head
 */
void print_list(node const* head);

/**
 * @brief Demonstrates linkedList reversal
 *
 * @return EXIT_SUCCESS on successful completion
 */
int main(int argc, char* argv[argc + 1]) {
    register constexpr size_t N = 10;    // number of nodes to test.
    // dummy head
    register node* head = calloc(1, SIZEOF_VARTYPE(*head));
    register node* x = head;

    // build up the list
    for (register size_t i = 1; i <= N; i++) {
        register node* t = calloc(1, SIZEOF_VARTYPE(*head));
        t->next = nullptr;
        t->k = i;
        x->next = t;
        x = x->next;
    }

    print_list(head);
    print_list(reverse(head));

    free(head);
    return EXIT_SUCCESS;
}

node* reverse(node* const x) {
    register node* y = x->next;    //
    register node* r = nullptr;    // reversed list

    while (y != nullptr) {
        node* t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    x->next = r;
    return x;
}

void print_list(node const* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}