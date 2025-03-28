/*

Exercise 3.50

Linked List Interface

Modification of Linked List Interface from Program 3.12
to use malloc and free directly.

*/
#pragma once
#include <stddef.h>

/**
 * @brief Key value for a List Item
 *
 */
typedef size_t LISTItem;

/**
 * @brief LinkedList node
 * consisting of a @key
 * and next node.
 *
 * @see key
 */
typedef struct node LISTNode;

struct node {
    LISTItem item;
    LISTNode* next;
};

/**
 * @brief Allocates memory for and
 * returns a new node with key value k
 *
 * @param k
 * @return ListNode* pointing to a node with
 * key value k if there is sufficent memory allocated
 * for a new node, else nullptr.
 */
LISTNode* LISTnew_node(LISTItem const k);
/**
 * @brief delete the ListNode n and free its
 * associated memory.
 *
 * @param n valid ListNode*
 */
void LISTfree_node(LISTNode* const n);

/**
 * @brief Insert the node y after x
 *
 * @param x node such that x->next = y after function call
 * @param y node to be inserted in the list containing x
 */
void LISTinsert_next(LISTNode* const x, LISTNode* const y);
/**
 * @brief Delete the node after x from the LinkedList
 * and return it's pointer
 *
 * @param x node *before* the node to be deleted
 * @return ListNode* deleted node if it exists, else nullptr
 */
LISTNode* LISTdelete_next(LISTNode* const x);
/**
 * @brief Returns the next node in the list
 * after x
 *
 * @param x - ListNode*
 * @return ListNode* x->next if it exists, else nullptr
 */
LISTNode* LISTnext(LISTNode const* const x);
/**
 * @brief Returns the key value of the node x
 *
 * @param x ListNode*
 * @return ListItem key value of x
 */
LISTItem LISTitem(LISTNode const* const x);

/**
 * @brief Prints out a representation of the list
 * pointed to by h
 */
void LISTprint_list(LISTNode const* h);
