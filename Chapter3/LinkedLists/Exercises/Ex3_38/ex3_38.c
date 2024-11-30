/*
Exercise 3.38
Write a function that takes a link to a list as argument
and returns a link to a copy of the list (a new list
containing all the same items, in the same order)
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
void printList(node* head);
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
node* copyList(node* head) {

    node* new_head = malloc(sizeof(typeof_unqual(*new_head)));
    node* tail = new_head;

    for (head=head->next; head != nullptr; head = head->next) {
        tail->next = malloc(sizeof(typeof_unqual(*head)));
        tail = tail->next;
        tail->k = head->k;
    }
    tail->next = nullptr;
    return new_head;
}

int main(int argc, char* argv[argc+1]) {

    //generate a list of N nodes numbered 1 to 10 with a dummy head
    node* nodes = malloc((N+1)*sizeof(typeof_unqual(*nodes)));

    for (size_t i = 1; i <= N; i++) {
        nodes[i-1].next = &nodes[i];
        nodes[i].k = i;
    }
    nodes[N].next = nullptr;

    printf("Initial List:\n");
    printList(nodes);
    node* new_head = copyList(nodes);
    printf("Copied list:\n");
    printList(new_head);

    return EXIT_SUCCESS;
}

void printList(node* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}