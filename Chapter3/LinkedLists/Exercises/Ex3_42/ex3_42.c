/*
Exercise 3.42

Implements a version of program 3.11 that does not use
head nodes.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
#define N 10
/**
 * @brief Exclusive upper bound on valid key values
 * 
 */
#define MAX_KEY 1000

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
int main(int argc, char* argv[argc+1]) {
    node* head_i = nullptr; //pointer to head of input
    node* t = nullptr; //tail of input
    srand(time(nullptr));

    //generate the list
    for (size_t i = 0; i < N; i++) {
        if (!t) { //handle case where list is initially empty
            head_i = malloc(sizeof(typeof_unqual(*t)));
            t = head_i;
        }
        else {
            t->next = malloc(sizeof(typeof_unqual(*t)));
            t = t->next;
        }
        t->next = nullptr;
        t->k = rand() % MAX_KEY;
    }

    for (node* h = head_i; h != nullptr; h = h->next) printf("%zu->", h->k);
    printf("X - unsorted input\n");

    //perform insertion sort
    node* head_o = nullptr; //head of insertion sort
    node* x = nullptr; //scan for sorted list
    node* u = nullptr; //start of unaccessed sorted list

    for (t = head_i; t != nullptr; t = u) {
        u = t->next;
        if (!head_o) { //handle case list initially empty
            head_o = t;
            head_o->next = nullptr;
        } else { 
            if  (head_o->k > t->k) { //handle case new node is new head
                t->next = head_o;
                head_o = t;
            }
            else {
                for (x = head_o; x->next != nullptr; x = x->next) {
                    if (x->next->k > t->k) break;
                }
                t->next = x->next;
                x->next = t;
            }
        }
    }
    for (node* h = head_o; h != nullptr; h = h->next) printf("%zu->", h->k);
    printf("X - sorted output\n");

    return EXIT_SUCCESS;
}