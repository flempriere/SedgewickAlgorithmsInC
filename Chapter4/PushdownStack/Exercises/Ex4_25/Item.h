/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Item for use in the double stack. Note we technically don't use
 * the traditional item interface, since we don't need the features.
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
 * @brief Union holding the value of an Item.
 *
 * 
 */
typedef union Item {
    Operator operator;
    Number number;
} Item;

/**
 * @brief Given a number wrap it in an Item struct.
 * 
 * @param x number to wrap
 * @return Item with the appropriate type and number set.
 */
#define itemFromNumber(x) (Item) {.number = x}

/**
 * @brief Given an operator wrap it in an Item struct
 * 
 * @param a Operator to wrap
 * @return Item containing a, and the indicated type.
 */
#define itemFromOperator(a) (Item) {.operator = a}




