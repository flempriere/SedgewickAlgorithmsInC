/*
Exercise 3.37

Implement a function for linked lists that exchanges the positions of the
nodes after the nodes nodes referenced by two given links t and u.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_N 10
#define MAX_NUM 100

#define ISEVEN(x) (((x) % 2) == 0)

#define SINGLE_EXCHANGE(a, b) do {  \
    a->next = b##_nxt;              \
    b->next = b##_nxt->next;        \
    b##_nxt->next = b;              \
} while(0)                          \

typedef struct node node;

struct node {
    size_t k;
    node* next;
};

void printList(node* head);
void ExchangeAfter(node* t, node* u);

int main(int argc, char* argv[argc+1]) {
    
    //generate a list of N random numbers with a dummy head
    size_t N = (argc == 2) ? strtoull(argv[1], nullptr, 0) : DEFAULT_N;
    node* nodes = malloc((N+1)*sizeof(typeof_unqual(*nodes)));

    srand(time(NULL));
    for (size_t i = 1; i <= N; i++) {
        nodes[i-1].next = &nodes[i];
        nodes[i].k = i;
    }
    nodes[N].next = nullptr;

    printf("Initial List:\n");
    printList(nodes);
    size_t i = rand() % (N + 1);
    size_t j = rand() % (N + 1);
    ExchangeAfter(&nodes[i], &nodes[j]);
    printf("List after exchange of nodes after %zu & %zu (0 represents the head):\n",
        i, j);
    printList(nodes);

    return EXIT_SUCCESS;
}

void printList(node* head) {
    size_t cntr = DEFAULT_N;
    for (head = head->next; head != nullptr && cntr; head = head->next, cntr--) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}

void ExchangeAfter(node* t, node* u) {
    node* t_nxt = t->next;
    node* u_nxt = u->next;

//return if either is nullptr or they are the same node

    if (!(t_nxt && u_nxt) || t == u) return;
    if (t_nxt == u) {
        SINGLE_EXCHANGE(t, u);
    } else if (u_nxt == t) {
        SINGLE_EXCHANGE(u, t);
    } else {
        t->next = t_nxt->next;
        t_nxt->next = u_nxt->next;
        u->next = t_nxt;
        u_nxt->next = t->next;
        t->next = u_nxt;
    }
}