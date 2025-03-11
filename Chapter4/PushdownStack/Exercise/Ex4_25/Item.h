/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Item interface for operator or number to allow both to be stored
 * in the same double stack ADT.
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once 
#include "Operator.h"
#include "Number.h"
#include <stdint.h>

/**
 * @brief enum indicating if Item is storing a number or operator
 * 
 */
typedef enum e_NumOrOperator {
    ITEM_NUM,
    ITEM_OPERATOR
 } e_NumOrOperator;

/**
 * @brief Union holding the value of an Item.
 *
 * 
 */
typedef union ItemValue {
    Operator operator;
    Number number;
} ItemValue;

typedef struct Item {
    e_NumOrOperator type;
    ItemValue value;
} Item;

/**
 * @brief Compare two Items for equality
 * 
 * @param A first Item to compare 
 * @param B second Item to compare
 * @return true if items equal else
 * @return false 
 */
static inline bool ITEMeq(Item A, Item B) {
    if (A.type == B.type) {
        if (A.type == ITEM_OPERATOR) {
            return OPERATOReq(A.value.operator, B.value.operator);
        }
        else if (A.type == ITEM_NUM) {
            return NUMBEReq(A.value.number, A.value.number);
        }
        else {
            return false;
        }
    }
    return false;
}

/**
 * @brief Print the value of an Item
 * 
 * @param A Item to print
 */
static inline void ITEMshow(Item A) {
    if (A.type == ITEM_OPERATOR) OPERATORshow(A.value.operator);
    else if (A.type == ITEM_NUM) NUMBERshow(A.value.number);
    else return;
}

/**
 * @brief Given a number wrap it in an Item struct.
 * 
 * @param x number to wrap
 * @return Item with the appropriate type and number set.
 */
static inline Item itemFromNumber(Number x) {
    return (Item) {.type = ITEM_NUM, .value =  (ItemValue) {.number = x}};
}

/**
 * @brief Given an operator wrap it in an Item struct
 * 
 * @param a Operator to wrap
 * @return Item containing a, and the indicated type.
 */
static inline Item itemFromOperator(Operator a) {
    return (Item) {.type = ITEM_OPERATOR, .value = (ItemValue) {.operator = a}};
}




