/**
 * @file stack.h
 * @brief This interface defines the basic operations that
 * define a pushdown stack. We assume that the four declarations
 * here are in a file stack.h (see this one), which is referenced
 * as an include by client programs that use these functions and
 * implementations that define Item, perhaps by including an Item.h
 * file. The argument to STACKInit specifies the maximum number of items
 * expected on the stack.
 * 
 * This version is modified to support two different stacks, one of operators
 * one of operands.
 * 
 * @version 0.1
 * @date 2025-03-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <stdlib.h>
#include "Operator.h"
#include "Number.h"

/**
 * @brief Maximum capacity of the operator stack
 * 
 * @param capacity 
 */
void STACKoperatorStackInit(size_t capacity);

/**
 * @brief Maximum capacity of the operand stack
 * 
 * @param capacity 
 */
void STACKoperandStackInit(size_t capacity);

/**
 * @brief Check if the operator stack is empty
 * 
 * @return true if empty, else
 * @return false
 */
bool STACKoperatorStackEmpty(void);

/**
 * @brief Check if the operand stack is empty
 * 
 * @return true if empty, else
 * @return false
 */
bool STACKoperandStackEmpty(void);

/**
 * @brief Push an Operator i onto the stack
 * 
 * @param i 
 */
void STACKoperatorStackPush(Operator i);

/**
 * @brief Push an operand i onto the stack
 * 
 * @param i 
 */
void STACKoperandStackPush(Number i);

/**
 * @brief Returns the Operator on top of the operator stack
 * 
 * @return Operator
 */
Operator STACKoperatorStackPop(void);

/**
 * @brief Returns the Number on top of the stack
 * 
 * @return Number
 */
Number STACKoperandStackPop(void);