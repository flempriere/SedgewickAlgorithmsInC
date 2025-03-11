/**
 * @file stackList.c
 * @brief This code implements the stack ADT using a linkedList
 * An auxiliary function NEW is used to allocate the memory for
 * a node, set its fields and return a link to the node.
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdlib.h>
#include "Item.h"
#include "stack.h"

/**
 * @brief Linked List structure representing a stack.
 * Contains an item on the stack and link to the previously
 * pushed member.
 */
typedef struct STACKnode STACKnode;

struct STACKnode {
    Item item;
    STACKnode* next;
};

/**
 * @brief Private variable pointing to the top of the stack
 * 
 */
static STACKnode* head;

/**
 * @brief Creates a new stack node with value
 * @item and pointing to @next. 
 * 
 * @param item 
 * @param next 
 * @return STACKnode* pointer to new STACKnode
 */
STACKnode* NEW(Item item, STACKnode* next) {
    STACKnode* x = malloc(sizeof(typeof(*x)));
    x->item = item;
    x->next = next;
    
    return x;
}

void STACKinit(size_t maxN) {
    //reset stack
    head = nullptr;
}

bool STACKempty() {
    return (head == nullptr);
}

void STACKpush(Item item) {
    head = NEW(item, head);
}

Item STACKpop() {

    Item item = head->item;
    STACKnode* t = head->next;
    free(head);
    head = t;

    return item;
}

