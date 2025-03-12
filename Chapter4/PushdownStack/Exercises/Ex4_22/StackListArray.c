/**
 * @file StackListArray.c
 * @author Felix Lempriere
 * @brief Stack imlementation utilising a Linked List array
 * implementation.
 *
 * 
 * 
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include "stack_v3.h"

 typedef size_t link;

 static Item* value;
 static link* next;

 static link head; //stores the link to next use

 static link next_free;

 static size_t size;


 bool STACKinit(size_t capacity) {

    //use a dummy head at the 0 index.
    value = malloc((capacity+1)* sizeof(typeof(*value)));
    if (!value) {
        STACKerror("failed to allocate stack");
        return false;
    }
    next = malloc((capacity+1) * sizeof(typeof(next)));
    if (!next) {
        STACKerror("failed to allocate stack");
        return false;
    }
    size = capacity;
    for (size_t i = 0; i <= capacity; i++) {
        next[i] = (i + 1);
    }
    head = 0;
    next_free = 1;
    return true;
}

size_t STACKcount(void) {
    size_t len = 0;
    for (link cur = head; cur; cur = next[cur], len++);
    return len;
}

/**
 * @brief Makes a new node and sets prepends it to the
 * list started by nxt.
 * 
 * @param i value to store in the node
 * @param nxt the node after this new node.
 * @return link, link to this node, if creating the node
 * fails then @return 0.
 */
link NEW(Item i, link nxt) {
    //get and adjust node from free list.
    if (next_free > size) return 0;
    link T = next_free;
    next_free = next[T];

    next[T] = nxt;
    value[T] = i;
    return T;
}

bool STACKpush(Item i) {
    link t = NEW(i, head);
    if (!t) return false;
    head = t;
    return true; 
}

bool STACKpop(Item* dest) {
    if (head) {
        *dest = value[head]; // get value
        link t = next[head]; // save the new head

        //put node back onto the free list
        next[head] = next_free;
        next_free = head;

        //shift head
        head = t;
        return true;
    }
    STACKerror("stack empty");
    return false;
}


void STACKerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}
