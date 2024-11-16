/*
Exercise 3.34

Write a function that moves the largest item on a given list to be
the final node on a list.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_N 10
#define MAX_NUM 100

typedef struct node node;

struct node {
    size_t k;
    node* next;
};

void printList(node* head);
void moveLargestToEnd(node* h);

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
    printList(nodes);
    moveLargestToEnd(nodes);
    printf("List after largest moved to end:\n");
    printList(nodes);

    return EXIT_SUCCESS;
}

void printList(node* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}

void moveLargestToEnd(node* h) {
    if (!(h->next)) return; //empty list
    node* max_pred = h; //the predecessor to the current max
    for (h = h->next; h->next; h = h->next) {
        if (h->next->k > max_pred->next->k) max_pred = h; 
    }
    if (max_pred->next == h) return; //max element is the last
    node* max = max_pred->next;
    max_pred->next = max->next;
    h->next = max;
    max->next = nullptr;
}