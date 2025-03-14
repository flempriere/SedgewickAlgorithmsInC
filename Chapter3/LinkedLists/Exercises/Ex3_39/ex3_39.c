/*
Exercise 3.39

Write a function that takes two arguments - a link to a list
and a function that takes a link as an argument - and removes
all items on the given list for which the function returns
a nonzero value
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of random nodes
 * to generate for test driver.
 */
#define N 10
/**
 * @brief Exlusive upper bound for random node key values
 * 
 */
#define MAX_NUM 100

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
void LISTprintList(node* head);
/**
 * @brief test if the key associated with a
 * node is even.
 * 
 * @param l 
 * @return true if l->k is even else
 * @return false 
 */
bool is_even(node* l);

void removeNodesByFunction(node* h, bool cmp(node*));

/**
 * @brief Test driver, generate a list of nodes
 * numbered 1 to 10 with a dummy head, then using
 * the function is_even remove all even nodes.
 * 
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc+1]) {
    
    //generate a list of N nodes numbered 1 to 10 with a dummy head
    node* nodes = malloc((N+1)*sizeof(typeof_unqual(*nodes)));

    for (size_t i = 1; i <= N; i++) {
        nodes[i-1].next = &nodes[i];
        nodes[i].k = i;
    }
    nodes[N].next = nullptr;

    printf("Initial List:\n");
    LISTprintList(nodes);
    removeNodesByFunction(nodes, is_even);
    printf("List after removal:\n");
    LISTprintList(nodes);

    return EXIT_SUCCESS;
}

void LISTprintList(node* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}

bool is_even(node* l) {
    return (!(l->k % 2)) ? true : false; 
}

void removeNodesByFunction(node* h, bool cmp(node*)) {

    for (; !(h == nullptr || h->next == nullptr); h=h->next) {
        if (cmp(h->next)) {
            node* h_nxt = h->next;
            h->next = h_nxt->next;
        }
    }
}



