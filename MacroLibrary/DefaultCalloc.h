/**
 * @file DefaultCalloc.h
 * @author Felix Lempriere (you@domain.com)
 * @brief Provides some default argument versions of calloc.
 * @version 0.1
 * @date 2025-03-28
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

#include "DefaultArguments.h"

#include <stdlib.h>

/**
 * @brief Calloc with optional arguments, by default with no arguments
 * this function will return one byte. This avoids the implementation
 * defined behaviour of returning a size 0.
 *
 * @remark use case 1: DEFAULTCalloc() - returns a block of memory for one char
 * use case 2: DEFAULTCalloc(n) - returns a block of memory for n chars
 * use case 3: DEFAULTCalloc(, x) - returns a block of memory for a single
 * typeof(x)
 * use case 4: DEFAULTCalloc(n, x) - returns a block of memory for n
 * typeof(x).
 */
#define DEFAULTCalloc(...) CALL2(calloc, 1, sizeof(char), __VA_ARGS__)

/**
 * @brief Allocate enough memory for a single instance of a variable x.
 *
 * @param x variable to instance.
 */
#define DEFAULTCallocVAR(x) calloc(1, sizeof(x))

/**
 * @brief Allocate enough memory for n instances of a variable x.
 *
 * @param n Number of instances of x to instantiate.
 * @param x Variable to instance.
 */
#define DEFAULTCallocNVAR(n, x) calloc(n, sizeof(x))
