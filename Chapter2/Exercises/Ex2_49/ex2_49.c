/*
    Exercise 2.49:
        Write a driver that generates M random integers and puts them in
        an array, then counts the number of N random integers that matches
        one of the numbers in the array via sequential search.

        Run the program for M = 10, 100, 1000 and N = 10, 100, 1000

    Play around with changing the typedef and corresponding KEY_MAX to different
    size integers.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Maximum number of random integers to generate
 * for testing
 */
#define MAX_N 100000

/**
 * @brief Maximum number of random integers to store 
 * 
 */
#define MAX_M 100000

/**
 * @brief Number of test cases to generate.
 * 
 */
#define CASES 5

/**
 * @brief Array key values
 * 
 */
typedef uint16_t key;

/**
 * @brief Largest valid key value
 * 
 */
#define KEY_MAX UINT16_MAX

/**
 * @brief Fills an array of a of length
 * len with random integers from 0 to KEY_MAX
 * 
 * @see KEY_MAX
 */
void fill_array(size_t len, key a[len]);

/**
 * @brief Generate n random integers and
 * test how many are contained in the array
 * a of size m
 * 
 * @return size_t number of matches
 */
size_t countMatches(size_t n, size_t m, key a[m]);

/**
 * @brief Value representing a value not in search 
 * 
 */
#define NOT_FOUND SIZE_MAX

/**
 * @brief Finds the index of v in a searching
 * from l to r.
 * 
 * @return idx of v if found else NOT_FOUND
 * 
 * @see NOT_FOUND
 */
size_t search(key v, size_t l, size_t r, key a[r+1]);

/**
 * @brief Generates M random integers and puts them in
 * an array, then counts the number of N random integers
 * that matches one of the numbers in the array, using
 * sequential search. Repeats for M = 10, 100, 1000 and
 * N = 10, 100, 1000. 
 * 
 */
int main(int argc, char* argv[argc + 1]) {

    key random_ints[MAX_M];
    size_t cases[CASES] = {10, 100, 1000, 10000, 100000};

    srand(time(NULL));
    for (size_t i = 0; i < CASES; i++) { //choose M case
        size_t m = cases[i];
        fill_array(m, random_ints);

        for (size_t j = 0; j < CASES; j++) { //choose N case
            size_t n = cases[j];
            size_t matches = countMatches(n, m, random_ints);
            printf("M: %zu, N: %zu, Matches: %zu\n", m, n, matches);
        }
    }

    return 0;
}

size_t search(key v, size_t l, size_t r, key a[r+1]) {
    for (; l <= r; l++) {if (v == a[l]) return l;}
    return SIZE_MAX;
}

size_t countMatches(size_t n, size_t m, key a[m]) {
    size_t matches = 0;
    for (; n < SIZE_MAX; --n) {
        key num = rand() % KEY_MAX;
        matches += (search(num, 0, m - 1, a) == SIZE_MAX) ? 0 : 1;
    }
    return matches;
}

void fill_array(size_t len, key a[len]) {
    while((--len) < KEY_MAX) {
        a[len] = rand() % KEY_MAX;
    }
}