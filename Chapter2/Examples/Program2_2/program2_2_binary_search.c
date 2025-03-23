/*
    Program 2.2 Binary search

    Assuming a is a sorted array, then if a[i] > v, v must be to the left of
   a[i] in the array, conversely if a[i] < v, v must be to the right.

    Binary search:
        recursively split the array at the midpoint (l + r) / 2 and check
        which half v is in until a[midpoint] = v or the array to check is empty

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
        0, 10, 20, 30, 40, 50, 60, 70, 80, 90,
    };

    for (register Item i = 0; i <= N; i++) {
        size_t idx = search(i * 10, 0, N - 1, a);
        if (idx != NOT_FOUND) {
            printf("v: %zu, idx: %zu, a[idx]: %zu\n", i * 10, idx, a[idx]);
        } else {
            printf("v: %zu, idx: NOT_FOUND\n", i * 10);
        }
    }
    return EXIT_SUCCESS;
}

size_t search(Item const v, register size_t l, register size_t r,
              Item a[r + 1]) {
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