/*
Exercise 3.55

Using the same assumptions as Ex3_54 (i.e. no nullptrs,
no modifying nodes and constant memory space)

Determine if two nodes eventually end up on the same cycle.

This uses a test structure of

1->2->3->4->5->3
6->7->3
8->9->10->8
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
 * @brief Converts a boolean value to the
 * corresponding string literal representation
 * 
 */
#define BOOL2STR(x) (x) ? "true" : "false"

/**
 * @brief Checks if starting from two nodes, one
 * can follow links and eventually end up on the
 * same cycle.
 * 
 * @param x 
 * @param y 
 * @return true if both lead to the same cycle, else
 * @return false 
 */
bool eventuallySameCycle(node* x, node* y);
/**
 * @brief detects the presence of a cycle in a linked list
 * pointed to by h
 * 
 * @param h 
 * @return node* a node on the cycle if it exists, else nullptr
 */
node* detectCycle(node* h);


/**
 * @brief Tests eventuallySameCycle using a list
 * containing a dummy head and N nodes. The list
 * structure is as follows
 * 
 * 1->2->3->4->5->3
 * 6->7->3
 * 8->9->...->N->8
 * 
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc+1]) {

    node* nodes = malloc((N+1)*sizeof(typeof(*nodes)));
    
    //build up node structure.
    for (size_t i = 1; i <= N; i++) {
        nodes[i].item = i;
        nodes[i-1].next = &nodes[i];
    }
    nodes[5].next = &nodes[3]; //add cycle
    nodes[7].next = &nodes[3]; //add second branch into cycle
    nodes[N].next = &nodes[8]; //add last cycle

    printf("Test Case 1: On the same branch (1, 2)\n");
    printf("Expected true, Found: %s\n", 
        BOOL2STR(eventuallySameCycle(&nodes[1], &nodes[2])));

    printf("Test Case 2: On different branches (common cycle) (1, 6)\n");
    printf("Expected true, Found: %s\n", 
        BOOL2STR(eventuallySameCycle(&nodes[1], &nodes[6])));

    printf("Test Case 3: One in the cycle (common cycle) (1, 3)\n");
    printf("Expected true, Found: %s\n", 
        BOOL2STR(eventuallySameCycle(&nodes[1], &nodes[3])));

    printf("Test Case 4: One in the cycle (common cycle) (1, 4)\n");
    printf("Expected true, Found: %s\n", 
        BOOL2STR(eventuallySameCycle(&nodes[1], &nodes[4])));

    printf("Test Case 5: Both in the cycle (common cycle) (4, 5)\n");
    printf("Expected true, Found: %s\n", 
        BOOL2STR(eventuallySameCycle(&nodes[4], &nodes[5])));

    printf("Test Case 6: On different cycles (1, 8)\n");
    printf("Expected false, Found: %s\n", 
        BOOL2STR(eventuallySameCycle(&nodes[1], &nodes[8])));

    printf("Test Case 7: On different cycles, both in their cycle (4, 8)\n");
    printf("Expected false, Found: %s\n", 
        BOOL2STR(eventuallySameCycle(&nodes[4], &nodes[8])));

    return EXIT_SUCCESS;
}

bool eventuallySameCycle(node* x, node* y) {

    node* cyc1 = detectCycle(x); //get element on the cycle
    node* cyc2 = detectCycle(y);

    //if one nullptr and other not -> can't be same cycle
    if ((!cyc1 && cyc2) || (cyc1 && !cyc2)) return false;
    //if both nullptr -> linear scan one to find other
    // then linear scan the other.
    if (!(cyc1 || cyc2)) {
        for (node* h = x; h != nullptr; h = h->next) {
            if (h == y) return true;
        }
        for (node* h = y; h != nullptr; h = h->next) {
            if (h == x) return true;
        }
        return false;
    }
    //both non nullptr -> check if same cycle
    node* cur = cyc1;
    do {
        if (cur == cyc2) return true;
        cur = cur->next;
    } while(cur != cyc1);
    return false;
}

node* detectCycle(node* h) {
    node* slow = h;
    node* fast = h;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return slow;
    }
    return nullptr;
}