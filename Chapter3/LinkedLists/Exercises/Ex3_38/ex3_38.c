/*
Exercise 3.38
Write a function that takes a link to a list as argument
and returns a link to a copy of the list (a new list
containing all the same items, in the same order)
*/

#include "../../../../MacroLibrary/DefaultCalloc.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of random nodes
 * to generate for test driver.
 */
constexpr unsigned int N = 10u;

/**
 * @brief Linked List node with
 * key and next element.
 *
 */
typedef struct node node;

struct node {
    size_t k;
    node* next;
};

/**
 * @brief Print out the LinkedList starting
 * from the node head.
 *
 * @param head
 */
void print_list(node const* head);
/**
 * @brief Creates a deep copy of the
 * list and returns a pointer to the copy.
 * The new head is a dummy head.
 *
 * @param head - start of the list to be copied,
 * assume a dummy head.
 *
 * @return node* pointer to new list
 */
node* copy_list(node const* head) {
    node* const new_head = CALLOC_FAILS_EXIT(*new_head);
    node* tail = new_head;

    for (head = head->next; head != nullptr; head = head->next) {
        tail->next = CALLOC_FAILS_EXIT(*tail->next);
        tail = tail->next;
        tail->k = head->k;
    }
    tail->next = nullptr;
    return new_head;
}

int main(int argc, char* argv[argc + 1]) {
    // generate a list of N nodes numbered 1 to 10 with a dummy head
    register node* const nodes = CALLOC_FAILS_EXIT(N + 1, *nodes);

    for (register size_t i = 1; i <= N; i++) {
        nodes[i - 1].next = &nodes[i];
        nodes[i].k = i;
    }
    nodes[N].next = nullptr;

    printf("Initial List:\n");
    print_list(nodes);

    register node* const new_head = copy_list(nodes);

    printf("Copied list:\n");
    print_list(new_head);

    return EXIT_SUCCESS;
}

void print_list(node const* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}