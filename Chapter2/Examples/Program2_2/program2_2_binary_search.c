/**
 * @file program2_2_binary_search.c
 * @author Felix Lempriere
 * @brief Implementation of binary search on a sorted array.
 *
 * @details
 * This program demonstrates the binary search algorithm, which efficiently
 * locates the position of a target value `v` within a sorted array `a`.
 *
 * - The algorithm works by repeatedly dividing the search interval in half:
 *   - If the target value `v` is less than the middle element, the search
 *     continues in the left half of the array.
 *   - If the target value `v` is greater than the middle element, the search
 *     continues in the right half of the array.
 *   - If the middle element equals `v`, the search is successful, and the
 *     index of `v` is returned.
 * - If the search interval becomes empty, the target value `v` is not present
 *   in the array, and the function returns `SIZE_MAX`.
 *
 * @note The input array `a` must be sorted in ascending order for the binary
 * search to work correctly.
 *
 * @return The index of the target value `v` if found, or `NOT_FOUND` if not
 * found.
 *
 * @version 0.1
 * @date 2025-04-07
 * @copyright Copyright (c) 2025
 */
#include "MacroLibrary/Array.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Defines the size of the test array used for demonstrating
 * the binary search algorithm.
 */
constexpr size_t N = 10u;

/**
 * @brief Typedef for the type of elements in the array being searched.
 *
 * This typedef is used to clearly distinguish between the type of the
 * elements being searched (Item) and the indices used for searching.
 */
typedef size_t Item;

/**
 * @brief Sentinel value returned when the search
 * fails to locate the specified value in the array.
 */
#define NOT_FOUND SIZE_MAX

/**
 * @brief Performs a binary search to find the index of a target value in a
 * sorted array.
 *
 * This function searches for the target value `v` within the sorted array `a`
 * between the indices `l` (inclusive) and `r` (exclusive). It uses the binary
 * search algorithm, which repeatedly divides the search interval in half.
 * If the target value is found, the function returns its index; otherwise,
 * it returns a predefined constant `NOT_FOUND`.
 *
 * @param a The sorted array of integers to search in. The array must have at
 * least `r + 1` elements.
 * @param v The target value to search for.
 * @param l The starting index of the search range (inclusive).
 * @param r The ending index of the search range (exclusive).
 * @return The index of the target value `v` if found, otherwise `NOT_FOUND`.
 *
 * @pre a[i] < a[i+1] for all i in [l, r - 1]. (The array must be sorted.)
 * @pre The indices [l, r) are valid for the array 'a'.
 * @pre a is not a nullptr.
 *
 * @post Returns i s.t. a[i] == v if v is found in the array, else NOT_FOUND.
 * @see NOT_FOUND A constant representing the value returned when the target is
 * not found.
 */
size_t search(Item const v, size_t const l, size_t const r,
              Item const a[const static r + 1]);

/**
 * @brief Test driver for the binary search function.
 *
 * Initializes a sorted array of integers and tests the binary
 * search implementation by searching for various target values. It iterates
 * through a range of values, calling the `search` function for each value,
 * and prints the results to the standard output.
 *
 * @return EXIT_SUCCESS if the program executes successfully.
 */
int main(int argc, char* argv[argc + 1]) {
    // Sorted array for binary search demonstration
    Item a[N] = {
        0, 10, 20, 30, 40, 50, 60, 70, 80, 90,
    };

    for (register Item i = 0; i <= N; i++) {
        register size_t idx = search(i * 10, 0, N - 1, a);
        if (idx != NOT_FOUND) {
            printf("v: %zu, idx: %zu, a[idx]: %zu\n", i * 10, idx, a[idx]);
        } else {
            printf("v: %zu, idx: NOT_FOUND\n", i * 10);
        }
    }
    return EXIT_SUCCESS;
}

size_t search(Item const v, size_t l, size_t r, Item const a[const static r + 1]) {
    assert(ARRAYIS_SORTED(r - l + 1, a + l, a[l]) && "Array is not sorted");
    while (r >= l) {
        register size_t m = (l + r) / 2;
        if (v == a[m]) return m;
        if (v < a[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return NOT_FOUND;
}