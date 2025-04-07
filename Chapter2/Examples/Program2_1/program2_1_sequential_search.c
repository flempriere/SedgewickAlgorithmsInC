/**
 * @file program2_1_sequential_search.c
 * @author Felix Lempriere
 * @brief Implementation of a sequential search algorithm.
 *
 * This program demonstrates a sequential search algorithm that checks if a
 * number `v` is present in an array indexed from `l` to `r`. The algorithm
 * scans the array from `l` to `r` until the value `v` is found or the array
 * is exhausted.
 *
 * @details
 * - If the value `v` is found, the function returns the index of `v`.
 * - If the value `v` is not found, the function returns the sentinel value
 * `NOT_FOUND`.
 *
 * @date 2025-04-07
 * @version 0.1
 * @copyright Copyright (c) 2025
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Defines the size of the test array used for demonstrating
 * the sequential search algorithm.
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
 * @brief Performs a sequential search to find the index of a target value in an
 * array.
 *
 * @details
 * This function searches for the target value `v` within the array `a` starting
 * from index `l` (inclusive) to index `r` (inclusive). It iterates through the
 * array elements one by one and returns the index of the first occurrence of
 * `v` if found. If the value is not found within the specified range, the
 * function returns a predefined constant `NOT_FOUND`.
 *
 * @param a The array to search within. The array must have at least `r + 1`
 * elements to ensure that the search range is valid.
 * @param l The starting index of the search range (inclusive).
 * @param r The ending index of the search range (inclusive).
 * @param v The target value to search for.
 * @return The index of the target value `v` if found, otherwise `NOT_FOUND`.
 *
 * @pre the indices [l, r] are valid for the array a.
 * @pre a is not a nullptr.
 *
 * @post returns index i s.t. a[i] == v or NOT_FOUND if v is not in a[l..r].
 *
 * @see NOT_FOUND A constant representing the value returned when the target is
 * not found.
 */
size_t search(Item const v, size_t l, size_t r, Item const a[const static r + 1]);

/**
 * @brief Test driver for the sequential search algorithm.
 *
 * This function initializes a test array and iterates through a range of
 * values to demonstrate the functionality of the `search` function. For each
 * value, it performs a sequential search within the array and prints the
 * result, indicating whether the value was found and its corresponding index
 * in the array.
 *
 * @return EXIT_SUCCESS upon successful execution of the program.
 */
int main(int argc, char* argv[argc + 1]) {
    Item a[N] = {
        0, 9, 1, 8, 2, 7, 3, 6, 4, 5,
    };

    for (register Item i = 0; i <= N; i++) {
        register size_t idx = search(i, 0, N - 1, a);

        if (idx != NOT_FOUND) {
            printf("Value searched: %zu, Found at index: %zu, Array value at "
                   "index: %zu\n",
                   i, idx, a[idx]);
        } else {
            printf("Value searched: %zu, Result: NOT_FOUND\n", i);
        }
    }
    return EXIT_SUCCESS;
}

size_t search(Item const v, size_t l, size_t r, Item const a[const static r + 1]) {
    for (; l <= r; l++) {
        if (v == a[l]) return l;
    }
    return NOT_FOUND;
}