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
    node* a = &head_i;
    node* t = a;
    srand(time(nullptr));

    for (size_t i = 0; i < N; i++) {
        t->next = malloc(sizeof(typeof_unqual(*t)));
        t = t->next;
        t->next = nullptr;

        t->k = rand() % MAX_KEY;
    }
    for (node* h = a->next; h != nullptr; h = h->next) printf("%zu->", h->k);
    printf("X - unsorted input\n");
    node* b = &head_o;
    node* u = nullptr;

    b->next = nullptr;
    for (t = a->next; t != nullptr; t = u) {
        u = t->next;
        node* x = nullptr;
        for (x = b; x->next != nullptr; x = x->next) {
            if (x->next->k > t->k) break;
        }
        t->next = x->next;
        x->next = t;
    }
    for (node* h = b->next; h != nullptr; h = h->next) printf("%zu->", h->k);
    printf("X - sorted output\n");

    return EXIT_SUCCESS;
}