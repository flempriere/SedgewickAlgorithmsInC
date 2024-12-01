/*
Exercise 3.41

This function reverses a list, returning a pointer to the final node,
which is now the new head node. The first node link is now a nullptr.

Uses a dummy head representation.
*/
#include <stdlib.h>
#include <stdio.h>

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
node* reverse(node* x);

/**
 * @brief Demonstrates linkedList reversal
 * 
 * @return EXIT_SUCCESS on successful completion
 */
int main(int argc, char* argv[argc+1]) {

    size_t N = 10;
    //dummy head
    node* head = malloc(sizeof(typeof_unqual(*head)));
    node* x = head;
    
    //build up the list
    for (size_t i = 1; i <= N; i++) {
        node* t = malloc(sizeof(typeof_unqual(*head)));
        t->next = nullptr;
        t->k = i;
        x->next = t;
        x = x->next;
    }

    for (node* h = head->next; h != nullptr; h = h->next) {
        printf("%zu->", h->k);
    }
    printf("X\n");

    for (node* h = reverse(head)->next; h != nullptr; h = h->next) {
        printf("%zu->", h->k);
    }
    printf("X\n");

    return EXIT_SUCCESS;
}

node* reverse(node *x) {
    node* y = x->next; //
    node* r = nullptr; // reversed list

    while(y != nullptr) {
        node* t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    x->next = r;
    return x;
}