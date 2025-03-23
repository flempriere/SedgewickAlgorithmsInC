/*
    Program 2.1 Sequential Search

    Checks if a number v is in an array indexed from l to r by scanning
    the array from l to r until v is found or the array is exhausted.

    returns the index of v if found, else SIZE_MAX
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief size of the test search array
 *
 */
constexpr size_t N = 10u;

/**
 * @brief Typedef for an 'Item' we search for,
 * this is to make which parameters are indices
 * and which are values.
 *
 */
typedef size_t Item;

/**
 * @brief value indicating search failed to
 * find the given value.
 */
#define NOT_FOUND SIZE_MAX

/**
 * @brief Find the index of v in the array a
 * searching from start index l to stop index r.
 *
 * @return idx of v if found else NOT_FOUND
 *
 * @see NOT_FOUND
 */
size_t search(Item const v, size_t l, size_t r, Item a[r + 1]);

/**
 * @brief Test driver for search
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    Item a[N] = {
        0, 9, 1, 8, 2, 7, 3, 6, 4, 5,
    };

    for (register Item i = 0; i <= N; i++) {
        register size_t idx = search(i, 0, N - 1, a);

        if (idx != NOT_FOUND) {
            printf("v: %zu, idx: %zu, a[idx]: %zu\n", i, idx, a[idx]);
        } else {
            printf("v: %zu, idx: NOT_FOUND\n", i);
        }
    }
    return EXIT_SUCCESS;
}

size_t search(Item const v, register size_t l, register size_t r,
              Item a[r + 1]) {
    for (; l <= r; l++) {
        if (v == a[l]) return l;
    }
    return NOT_FOUND;
}