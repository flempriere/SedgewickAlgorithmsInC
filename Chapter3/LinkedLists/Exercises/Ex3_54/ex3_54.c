/*
Exercise 3.54

Write a code fragment that, given a pointer to a node, finds
the number of different nodes that it ultimately reaches
by following links from that node, without modifying the nodes.

Do not use more than a constant amount of extra memory space.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Number of nodes to generate
 * 
 */
const size_t N = 10;

/**
 * @brief Number of test cases to generate
 * 
 */
const size_t M = 10;

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
    key item;
    node* next;
};

/**
 * @brief Returns an idx between 1 and N
 * 
 */
#define GET_IDX() (rand() % ((N)) + 1)

/**
 * @brief Counts the number of unique nodes
 * visited by following links from a starting
 * node h.
 * 
 * @param h 
 * @return size_t
 */
size_t countUniqueNodesVisited(node* h);

/**
 * @brief Detects if there is a cycle in a Linked List
 * and returns a pointer to where this cycle was found.
 * 
 * @param h 
 * @return node* a node on the cycle else @return nullptr
 * if there is no cycle
 */
node* DetectCycle(node* h);

/**
 * @brief Test's CountUniqueNodesVisited()
 * 
 * Generates a list of 10 nodes, randomly forms
 * a cycle by connecting the final node to a random
 * point.
 * 
 * We then count the number of nodes visited assuming
 * we start at the first node, versus the final node.
 * 
 * (i.e. potentially out of the cycle vs in the cycle)
 * 
 * This performed M times
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {

    srand(time(nullptr));

    //use a dummy head representation
    node* nodes = malloc((N+1)*sizeof(typeof(*nodes)));

    for (size_t j = 0; j < M; j++) {

        for (size_t i = 1; i <= N; i++) {
            nodes[i].item = i;
            nodes[i-1].next = &nodes[i];
        }
        //randomly generate cycle
        size_t cycle_idx = GET_IDX();
        nodes[N].next = &nodes[cycle_idx];

        printf("Test #%zu\nList has cycle starting at: %zu\n"
        "(0 denotes no cycle)\n", j, cycle_idx);

        printf("Number of nodes visted by first node: %zu\n",
        countUniqueNodesVisited(&nodes[1]));
        printf("Number of nodes visited by final node: %zu\n",
        countUniqueNodesVisited(&nodes[N]));
        printf("Expected number for first and final: %zu, %zu\n",
        N, (N - cycle_idx) + 1);
    }

    return EXIT_SUCCESS;
}

size_t countUniqueNodesVisited(node* h) {
    node* cycle;
    if ((cycle = DetectCycle(h))) {
        size_t n_unique = 1;
        if (cycle != h) { //need to find start of cycle
            for (node* cur = h; cur != cycle; 
                cur=cur->next, cycle=cycle->next) {
                n_unique++;
            }
        } //count size of the cycle
        for (node* cur = cycle->next; cur != cycle; 
            cur=cur->next) {
            n_unique++;
        }
        return n_unique;
    }
    size_t n_unique = 0;
    for (; h != nullptr; h = h->next) n_unique++;
    return n_unique;
}

node *DetectCycle(node *h)
{
    node* slow = h;
    node* fast = h;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return slow;
    }
    return nullptr;
}
