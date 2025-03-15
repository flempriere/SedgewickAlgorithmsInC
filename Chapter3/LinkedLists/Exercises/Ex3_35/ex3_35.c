/*
Exercise 3.35

Write a function that moves the smallest item on a given list to the be
first node on a list

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Number of random nodes to generate for test driver
 * 
 */
#define DEFAULT_N 10
/**
 * @brief Exlusive upper bound for random node key values
 * 
 */
#define MAX_NUM 100
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
void LISTprintList(node* head);
/**
 * @brief move the smallest element of the list
 * starting at h to the start of the list.
 * 
 * @param h 
 */
void moveSmallestToFront(node* h);

/**
 * @brief Checks that the smallest element of the list
 * starting at h is at the end.
 * 
 * @return true if the first element is the smallest else
 * @return false 
 */
bool assertSmallestAtFront(node* h);

int main(int argc, char* argv[argc+1]) {
    
    //generate a list of N random numbers with a dummy head
    size_t N = (argc == 2) ? strtoull(argv[1], nullptr, 0) : DEFAULT_N;
    node* nodes = malloc((N+1)*sizeof(typeof_unqual(*nodes)));

    srand(time(NULL));
    for (size_t i = 1; i <= N; i++) {
        size_t k = rand() % MAX_NUM;
        nodes[i-1].next = &nodes[i];
        nodes[i].k = k;
    }
    nodes[N].next = nullptr;

    printf("Initial List:\n");
    LISTprintList(nodes);
    moveSmallestToFront(nodes);
    printf("List after largest moved to end:\n");
    LISTprintList(nodes);
    printf("Smallest at the front?: %s\n", 
        (assertSmallestAtFront(nodes) ? "true" : "false"));

    return EXIT_SUCCESS;
}

void LISTprintList(node* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}

void moveSmallestToFront(node* h) {
    if (!(h->next)) return; //empty list
    node* min_pred = h; //the predecessor to the current min
    for (node* cur = h->next; cur->next; cur = cur->next) {
        if (cur->next->k < min_pred->next->k) min_pred = cur; 
    }
    if (min_pred == h) return; //min element is first

    node* min = min_pred->next;
    min_pred->next = min->next;
    min->next = h->next;
    h->next = min;
}

bool assertSmallestAtFront(node* h) {
    h = h->next;
    size_t smallest = h->k;
    for (h=h->next; h != nullptr; h = h->next) {
        if (h->k < smallest) return false;
    }

    return true;
}
