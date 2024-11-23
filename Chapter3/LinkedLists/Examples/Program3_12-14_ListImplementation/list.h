/*
Linked List interface suggested in Program 3.11
*/

#include <stddef.h>

/**
 * @brief Key value for a List Item
 * 
 */
typedef size_t ListItem;

/**
 * @brief LinkedList node
 * consisting of a @key
 * and next node.
 * 
 * @see key
 */
typedef struct node ListNode;

struct node {
    ListItem item;
    ListNode* next;
};

/**
 * @brief Allocates room for N ListNodes
 * 
 * @param N > 0
 * 
 * @see ListNode
 */
void initNodes(size_t N);
/**
 * @brief Returns a new node with key value k
 * 
 * @param k 
 * @return ListNode* pointing to a node with
 * key value k if there is sufficent memory allocated
 * for a new node, else nullptr.
 */
ListNode* newNode(ListItem k);
/**
 * @brief Free node pointed to by n and return its
 * memory to the free list.
 * 
 * @param n valid ListNode*
 */
void freeNode(ListNode* n);
/**
 * @brief Insert the node y after x
 * 
 * @param x node such that x->next = y after function call
 * @param y node to be inserted in the list containing x
 */
void insertNext(ListNode* x, ListNode* y);
/**
 * @brief Delete the node after x from the LinkedList
 * and return it's pointer
 * 
 * @param x node *before* the node to be deleted
 * @return ListNode* deleted node if it exists, else nullptr
 */
ListNode* deleteNext(ListNode* x);
/**
 * @brief Returns the next node in the list
 * after x
 * 
 * @param x - ListNode* 
 * @return ListNode* x->next if it exists, else nullptr
 */
ListNode* next(ListNode* x);
/**
 * @brief Returns the key value of the node x
 * 
 * @param x ListNode*
 * @return ListItem key value of x
 */
ListItem Item(ListNode* x); 


