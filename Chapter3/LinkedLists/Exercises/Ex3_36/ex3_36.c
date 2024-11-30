/*
Exercise 3.36

Write a function that rearranges a linked list to put the nodes in even
positions after the nodes in odd positions in the list, preversing the
relative order of both the evens and the odds.

*/
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of random nodes to generate for test driver
 * 
 */
#define N 10

/**
 * @brief Returns if a number is even
 * @param x
 * @return true if even else @return false.
 */
#define ISEVEN(x) (((x) % 2) == 0)
/**
 * @brief Linked List node with
 * key and next element.
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
void printList(node* head);
/**
 * @brief Rearrange a linked list to put
 * the sublist of even indices before the
 * sublist of odd indices. The relative
 * order of each sublist is preserved.
 * 
 * @param h 
 */
void partitionOddsAndEvens(node* h);

/**
 * @brief Driver program to demonstrate PartitionOddsAndEvens.
 * We generate a list containing N elements keyed by their
 * position and then partition.
 * 
 * @return int 
 */
int main(int argc, char* argv[argc+1]) {
    
    //generate a list of N random numbers with a dummy head
    node* nodes = malloc((N+1)*sizeof(typeof_unqual(*nodes)));

    for (size_t i = 1; i <= N; i++) {
        nodes[i-1].next = &nodes[i];
        nodes[i].k = i;
    }
    nodes[N].next = nullptr;

    printf("Initial List:\n");
    printList(nodes);
    partitionOddsAndEvens(nodes);
    printf("List after partition:\n");
    printList(nodes);

    return EXIT_SUCCESS;
}

void printList(node* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}

void partitionOddsAndEvens(node* h) {
    node* oddHead = malloc(sizeof(typeof_unqual(*h)));
    node* oddTail = oddHead;
    node* evenHead = malloc(sizeof(typeof_unqual(*h)));
    node* evenTail = evenHead;

    //build two lists, one for odd, one for even
    node* cur = h->next;
    for (size_t idx = 0; cur != nullptr; cur = cur->next, idx++) {
        if (ISEVEN(idx)) {
            evenTail->next = cur;
            evenTail = cur;
        } else {
            oddTail->next = cur;
            oddTail = cur;
        }
    }
    //merge the odd and even lists
    evenTail->next = nullptr;
    oddTail->next = evenHead->next;
    h->next = oddHead->next;
    free(evenHead);
    free(oddHead);
}