/**
 * @file Ex3-1
 * @author Felix Lempriere
 * @brief Solution to Exercise 3.1.
 *
 * Calculates the limits of char, int, floats and doubles by
 * reference to <limits.h> and <float.h>.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief prints out the representable ranges
 * for integer and floating point types.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    printf("CHAR range: \n");
    printf("char: %d - %d \n", CHAR_MIN, CHAR_MAX);
    printf("signed char: %d - %d \n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: %u - %u\n", 0, UCHAR_MAX);

    printf("\nSHORT range: \n");
    printf("short: %d - %d \n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %u - %u\n", 0, USHRT_MAX);

    printf("\nINT range: \n");
    printf("int: %d - %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: %u - %u\n", 0, UINT_MAX);

    printf("\nLONG range: \n");
    printf("long: %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: %u - %lu\n", 0, ULONG_MAX);

    printf("\nLONG LONG range: \n");
    printf("long long: %lld - %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long: %u - %llu\n", 0, ULLONG_MAX);

    printf("\nFLOAT and DOUBLE range: \n");
    printf("smallest float: %e\n", FLT_MIN);
    printf("largest float: %e\n", FLT_MAX);
    printf("smallest double: %e\n", DBL_MIN);
    printf("largest double: %e\n", DBL_MAX);

    return EXIT_SUCCESS;
}
