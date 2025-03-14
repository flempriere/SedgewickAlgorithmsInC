/**
 * @file RandomQueue_List.c
 * @author Felix Lempriere
 * @brief Implementation of the RandomQueue Interface from Ex4_42
 * utilising a linked list. We use a circular doubly-linked list 
 * with a dummy head to make the process as time efficient as possible 
 * at the cost of extra space.
 *
 * We perform insertions by adding to the front of the linked list. In constant
 * time.
 *
 * We perform gets by generating a random number between 0 and (rq_size), we
 * then iterate to this indexed node, taking the 0-th index to be the most
 * recently inserted, then remove it. By using a doubly linked list with dummy
 * head we are able to traverse the list backwards to access nodes in the later
 * half of the list faster.
 *
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include "../../../AbstractObjects/Examples/intItem/Item.h"
 #include "../Ex4_42/RandomQueue.h"


 typedef struct RandomQueueNode RandomQueueNode;

 struct RandomQueueNode {
    Item value;
    RandomQueueNode* prev;
    RandomQueueNode* next;
 };

 /**
  * @brief Number of elements in the random queue.
  * 
  */
 static size_t rq_size;

 /**
  * @brief Head of the random Queue
  * 
  */
 static RandomQueueNode* head;


  bool RANDOMQUEUEinit(size_t size) {
    head = malloc(sizeof(typeof(*head)));
    if (!head) {
        RANDOMQUEUEerror("Failed to initialise random queue");
        return false;
    }
    head->next = head;
    head->prev = head;
    rq_size = 0;
    return true;
  }

  bool RANDOMQUEUEempty(void) {
    return (!rq_size);
  }

  /**
   * @brief Allocates and inserts a new node with value i into the linked list
   * after prev.
   * 
   * @param i value of the new node.
   * @param prev pointer to the node to insert the new pointer after.
   * @return RandomQueueNode* pointer to new node if successful else
   * @return nullptr.
   */
  static RandomQueueNode* RANDOMQUEUENEW(Item i, RandomQueueNode* prev) {
    RandomQueueNode* new = malloc(sizeof(typeof(*new)));
    if (!new) {
        RANDOMQUEUEerror("Failed to allocate memory for a new Random Queue Node");
        return nullptr;
    }
    new->value = i;
    new->next = prev->next;
    prev->next->prev = new;
    new->prev = prev;
    prev->next = new;
    
    return new;
  }

  bool RANDOMQUEUEput(Item i) {
    RandomQueueNode* new = RANDOMQUEUENEW(i, head);
    if (!new) return false;
    rq_size++;
    return true;
  }

  /**
   * @brief Gets the node at the given index where the 0-th index
   * is the next node from the dummy head.
   * 
   * Assumes that the RandomQueue is not empty and the node exists.
   *
   * @param idx 
   * @return RandomQueueNode* 
   */
  static RandomQueueNode* RANDOMQUEUEGETBYIDX(size_t idx) {
    RandomQueueNode* cur;
    if (idx > (rq_size / 2)) { //if over halfway come from the left
        idx = rq_size - idx;
        for (cur = head; idx; idx--, cur = cur->prev);
    } else { //come from the right
        for (cur = head->next; idx; idx--, cur=cur->next);
    }
    return cur;
  }

  bool RANDOMQUEUEget(Item* dest) {
    if (RANDOMQUEUEempty()) {
        RANDOMQUEUEerror("failed to get, random queue empty");
        return false;
    }
    size_t idx = rand() % rq_size;
    RandomQueueNode* got = RANDOMQUEUEGETBYIDX(idx);

    *dest = got->value;
    got->prev->next = got->next;
    got->next->prev = got->prev;
    free(got);
    rq_size--;
    return true;
  }

  void RANDOMQUEUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
  }





