/*
Exercise 3.42

Implements a version of program 3.11 that does not use
head nodes.
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
 * @brief Number of random numbers to generate
 *
 */
constexpr size_t N = 10u;
/**
 * @brief Exclusive upper bound on valid key values
 *
 */
constexpr unsigned int MAX_KEY = 1000u;

/**
 * @brief Print out a linked list starting at
 * the given node.
 *
 * @param head
 */
void print_list(node const* head);
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
    register node* head_i = nullptr;    // pointer to head of input
    register node* t = nullptr;         // tail of input

    RAND_SEED_TIME;

    // generate the list
    for (register size_t i = 0; i < N; i++) {
        if (!t) {    // handle case where list is initially empty
            head_i = calloc(1, SIZEOF_VARTYPE(*t));
            t = head_i;
        } else {
            t->next = calloc(1, SIZEOF_VARTYPE(*t));
            t = t->next;
        }
        t->next = nullptr;
        t->k = RAND_NUM(MAX_KEY);
    }
    printf("===unsorted input===\n");
    print_list(head_i);

    // perform insertion sort
    register node* head_o = nullptr;    // head of insertion sort
    register node* x = nullptr;         // scan for sorted list
    register node* u = nullptr;         // start of unaccessed sorted list

    for (t = head_i; t != nullptr; t = u) {
        u = t->next;
        if (!head_o) {    // handle case list initially empty
            head_o = t;
            head_o->next = nullptr;
        } else {
            if (head_o->k > t->k) {    // handle case new node is new head
                t->next = head_o;
                head_o = t;
            } else {
                for (x = head_o; x->next != nullptr; x = x->next) {
                    if (x->next->k > t->k) break;
                }
                t->next = x->next;
                x->next = t;
            }
        }
    }
    printf("===sorted output===\n");
    print_list(head_o);

    for (register node* cur = head_o; cur != nullptr;) {
        node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    return EXIT_SUCCESS;
}

void print_list(node const* h) {
    for (; h != nullptr; h = h->next) printf("%zu->", h->k);
    printf("X\n");
}