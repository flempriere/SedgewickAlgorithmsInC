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

#include "TraceMacro.h"

#include <stdlib.h>

/**
 * @brief Allocate enough memory for a single instance of a variable x.
 *
 * @param x variable to instance.
 */
#define CALLOCVAR(x) calloc(1, sizeof(x))

/**
 * @brief Allocate enough memory for n instances of a variable x.
 *
 * @param n Number of instances of x to instantiate.
 * @param x Variable to instance.
 */
#define CALLOCVAR_N(n, x) calloc(n, sizeof(x))

/**
 * @brief Calloc with optional arguments, by default takes in one variable
 * and returns enough memory for one instance of the variable. If a size is
 * optionally provided then
 *
 * @remark use case 1: DEFAULTCalloc(x) - returns a block of memory for one x
 * use case 2: DEFAULTCalloc(n, x) - returns a block of memory for n instances
 * of x
 * use case 3: DEFAULTCalloc(x, n) - fails, must follow calloc call structure.
 *
 * use case 4: DEFAULTCalloc(x, n, t) - fails too many args supplied. 
 */
#define CALLOC(x, ...) \
    CALLOCVAR##__VA_OPT__(_N)(x __VA_OPT__(, ) __VA_ARGS__)

/**
 * @brief Variant of calloc that checks alloc succeeds and calls exit if
 * unsuccessful.
 *
 * @param nmemb
 * @param size
 * @return void* allocated memory.
 */
static inline void* CALLOCexit_on_fail(size_t const nmemb, size_t const size) {
    void* res = calloc(nmemb, size);
    if (!res) {
        TRACE_CALL("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    return res;
}

/**
 * @brief Allocate enough memory for a single instance of a variable x.
 * Exits the program if allocation fails.
 *
 * @param x variable to instance.
 */
 #define CALLOCEXIT_FAIL_VAR(x) CALLOCexit_on_fail(1, sizeof(x))

 /**
  * @brief Allocate enough memory for n instances of a variable x.
  *
  * @param n Number of instances of x to instantiate.
  * @param x Variable to instance.
  */
 #define CALLOCEXIT_FAIL_VAR_N(n, x) CALLOCexit_on_fail(n, sizeof(x))
 
/**
 * @brief Version of @DEFAULTCALLOC that exits the program if
 * the allocation fails. 
 * 
 */
#define CALLOCEXIT_ON_FAIL(x, ...) \
    CallocEXIT_FAIL_VAR##__VA_OPT__(_N)(x __VA_OPT__(, ) __VA_ARGS__)
