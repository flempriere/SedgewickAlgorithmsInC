/*
Exercise 3.40

Write a function that takes two arguments - a link to a list
and a function that takes a link as an argument - removes those
arguments from the original list and returns them in a new list
*/

#include "../../../../MacroLibrary/Generic.h"
#include "../../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of random nodes
 * to generate for test driver.
 */
constexpr unsigned int N = 10u;

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
void print_list(node const* head);
/**
 * @brief test if the key associated with a
 * node is even.
 *
 * @param l
 * @return true if l->k is even else
 * @return false
 */
bool is_even(node const* const l);

node* partition_nodes_by_function(node* h, bool cmp(node const* const));

/**
 * @brief Test driver, generate a list of nodes
 * numbered 1 to 10 with a dummy head, then using
 * the function is_even to partition even nodes.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    // generate a list of N nodes numbered 1 to 10 with a dummy head
    node* const nodes = calloc(N + 1, SIZEOF_VARTYPE(*nodes));

    for (register size_t i = 1; i <= N; i++) {
        nodes[i - 1].next = &nodes[i];
        nodes[i].k = i;
    }
    nodes[N].next = nullptr;

    printf("Initial List:\n");
    print_list(nodes);
    node* eliminated = partition_nodes_by_function(nodes, is_even);
    printf("List after removal:\n");
    print_list(nodes);
    printf("New list after removal:\n");
    print_list(eliminated);

    return EXIT_SUCCESS;
}

void print_list(node const* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}

bool is_even(node const* const l) { return IS_EVEN(l->k); }

node* partition_nodes_by_function(node* h, bool cmp(node const* const)) {
    node* elimHead = malloc(sizeof(typeof_unqual(*elimHead)));
    node* elimTail = elimHead;

    for (; !(h == nullptr || h->next == nullptr); h = h->next) {
        if (cmp(h->next)) {
            node* h_nxt = h->next;
            h->next = h_nxt->next;
            elimTail->next = h_nxt;
            elimTail = elimTail->next;
        }
    }
    elimTail->next = nullptr;
    return elimHead;
}
