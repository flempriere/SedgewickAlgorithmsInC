/*
Exercise 3.36

Write a function that rearranges a linked list to put the nodes in even
positions after the nodes in odd positions in the list, preversing the
relative order of both the evens and the odds.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_N 10
#define MAX_NUM 100

#define ISEVEN(x) (((x) % 2) == 0)

typedef struct node node;

struct node {
    size_t k;
    node* next;
};

void printList(node* head);
void partitionOddsAndEvens(node* h);

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
    for (node* cur = h->next; cur != nullptr; cur = cur->next) {
        if (ISEVEN(cur->k)) {
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