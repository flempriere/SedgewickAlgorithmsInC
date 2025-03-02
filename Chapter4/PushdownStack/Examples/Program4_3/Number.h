/**
 * @file Number.h
 * @brief Sample interface providing a number
 * and corresponding operations. Typedef is used
 * to obscure the underlying type.
 * 
 * Extends the examples in Section 4.1 by providing
 * a function to extract a number from a string.
 * @version 0.1
 * @date 2024-12-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <limits.h>
#include <stdlib.h>

/**
 * @brief typedef to obscure underlying datatype
 * 
 */
typedef int Number;

static const Number NUM_MAX = INT_MAX;

/**
 * @brief Determine if two numbers are equal
 * 
 * @return @true if equal, else
 * @return @false
 */
#define NUMeq(A, B) ((A) == (B))

/**
 * @brief print the value of a number
 * 
 */
#define NUMshow(A) printf("%d", A)


/**
 * @brief Extracts a number from the string pointed
 * to by src, and stores it in the number pointed to
 * by dest and return the number of characters read.
 * 
 * In the case that a complete value could not be read
 * zero is returned.
 * 
 * @param src string to extract the item from
 * @param dest after successful function execution dest
 * stores the extracted value, in the case of an error
 * dest is untouched.
 * 
 * @return size_t indicating number of chars read or 0 in
 * the case of an error.
 * 
 * @remark This specific implementation is written for an
 * underlying integer type represented in decimal.
 */
static inline size_t NUMfromStr(char* src, Number* dest) {
    char* cur;
    Number val = 0;
    for (cur = src; isdigit(cur); cur++) {
        val = 10*val + (*cur - '0');
    }
    size_t len =  (size_t)(cur - src);
    if (len) *dest = val;
    return len;
}


