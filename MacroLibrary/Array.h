/**
 * @file Array.h
 * @author Felix Lempriere
 * @brief Provides some simple functions and macros for handling arrays.
 * @version 0.1
 * @date 2025-04-07
 *
 * @copyright Copyright (c) 2025
 *
 * @todo Make these functions use a type generic interface
 */

#pragma once
#include "MacroLibrary/DefaultArguments.h"
#include "MacroLibrary/Generic.h"
#include "MacroLibrary/TraceMacro.h"
#include "MacroLibrary/Utility.h"

#include <stddef.h>

/**
 * @brief Checks if an array is sorted in descending order.
 *
 * @param len The length of the array. Must be greater than 0.
 * @param a Pointer to the array to be checked. Must be non-null.
 * @param elem_size The size of each element in the array. Must be greater than
 * 0.
 * @param cmp Comparison function used to compare two elements, which returns:
 *   - a negative value if the first argument is less than the second,
 *   - zero if they are equal,
 *   - a positive value if the first argument is greater than the second.
 *
 * @pre the indices [0, len) are valid for the array a.
 *
 * @note Should be called through the ARRAYis_sorted function which provides
 * error handling.
 * @return true if the array is sorted in descending order, false otherwise.
 */
static bool ARRAYis_sorted_descending(size_t len, void const* a,
                                      size_t elem_size,
                                      int cmp(const void* a, const void* b));

/**
 * @brief Checks if an array is sorted in ascending order.
 *
 * @param len The length of the array. Must be greater than 0.
 * @param a Pointer to the array to be checked. Must be non-null.
 * @param elem_size The size of each element in the array. Must be greater than
 * 0.
 * @param cmp Comparison function used to compare two elements, which returns:
 *   - a negative value if the first argument is less than the second,
 *   - zero if they are equal,
 *   - a positive value if the first argument is greater than the second.
 *
 * @pre the indices [0, len) are valid for the array a.
 *
 * @note Should be called through the ARRAYis_sorted function which provides
 * error handling.
 * @return true if the array is sorted in ascending order, false otherwise.
 */
static bool ARRAYis_sorted_ascending(size_t len, void const* a,
                                     size_t elem_size,
                                     int cmp(const void* a, const void* b));

/**
 * @brief Checks if a is a sorted array.
 *
 * @param len The length of the array.
 * @param a Pointer to the array to be checked. Must be non-null.
 * @param elem_size The size of each element in the array. Must be greater than
 * 0.
 * @param cmp Comparison function used to compare two elements, which returns:
 *   - a negative value if the first argument is less than the second,
 *   - zero if they are equal,
 *   - a positive value if the first argument is greater than the second.
 * @param descending If true, check for descending order; otherwise, check for
 * ascending order.
 *
 * @pre the indices [0, len) are valid for the array a.
 * @return true if all parameters are valid and the array is sorted, else
 * @return false.
 */
bool ARRAYis_sorted(size_t len, void const* a, size_t elem_size,
                    int cmp(const void* a, const void* b), bool descending) {
    if (!len) { return true; }
    if (!a) {
        TRACE_CALL("Error: nullptr passed as array");
        return false;
    }
    if (!elem_size) {
        TRACE_CALL("Error: elem_size is 0");
        return false;
    }
    if (!cmp) {
        TRACE_CALL("Error: cmp function is nullptr");
        return false;
    }
    return (descending ? ARRAYis_sorted_descending :
                         ARRAYis_sorted_ascending)(len, a, elem_size, cmp);
}

static bool ARRAYis_sorted_descending(size_t len, void const* a,
                                      size_t elem_size,
                                      int cmp(const void* a, const void* b)) {
    register char* arr = CAST(char*) a;
    for (register size_t i = 0; i < len - 1; i++) {
        if (cmp(arr + i * elem_size, arr + (i + 1) * elem_size) < 0) {
            return false;
        }
    }
    return true;
}

static bool ARRAYis_sorted_ascending(size_t len, void const* a,
                                     size_t elem_size,
                                     int cmp(const void* a, const void* b)) {
    register char* arr = CAST(char*) a;
    for (register size_t i = 0; i < len - 1; i++) {
        if (cmp(arr + i * elem_size, arr + (i + 1) * elem_size) > 0) {
            return false;
        }
    }
    return true;
}

#define ARRAYIS_SORTED(LEN, A, ...)                                         \
    CALL5_ND4(ARRAYis_sorted, LEN, CAST(void*)(A), sizeof(*A), GET_CMP(*A), \
              false __VA_OPT__(, ) __VA_ARGS__)

/**
 * @brief Outputs the specified number of elements from an array to the standard
 * output.
 *
 * @param len length of the array, should be greater than zero.
 * @param a An array with a minimum size of `len`.
 * @param elem_size The size of each element in the array. Must be greater than
 * > 0.
 *
 * @pre the indices [0, len) are valid for the array a.
 */
void ARRAYprint_array(size_t const len, void* a, size_t elem_size,
                      void print_elem(const void* elem)) {
    for (register size_t i = 0; i < len; i++) {
        print_elem(CAST(char*) a + i * elem_size);
        if (i < len - 1) printf(" ");
    }
    printf("\n");
}

#define ARRAYPRINT(LEN, A, ...)                                      \
    do {                                                             \
        static_assert(is_array(A), #A " is not an array\n");         \
        CALL4_ND3(ARRAYprint_array, LEN, CAST(void*)(A), sizeof(*A), \
                  GET_PRINT(*A) __VA_OPT__(, ) __VA_ARGS__);         \
    } while (false);
