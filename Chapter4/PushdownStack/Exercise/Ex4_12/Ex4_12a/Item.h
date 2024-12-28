/**
 * @file Item.h
 * @brief Sample interface providing an item
 * and corresponding operations. Typedef is used
 * to obscure the underlying type.
 * 
 * Extends the examples in Section 4.1 by providing
 * a function to extract an Item from a string.
 * 
 * Uses the floating point interface developed in Exercise 
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <limits.h>
#include <float.h>
#include <tgmath.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * @brief typedef to obscure underlying datatype
 * 
 */
typedef double Item;

static const Item ITEM_MAX = DBL_MAX;

/**
 * @brief tolerance for floating point equality
 * 
 */
#define TOL 1e-6

/**
 * @brief Test for equality of two items
 * 
 * @param A 
 * @param B 
 * @return true i equal else
 * @return false 
 */
inline bool eq(Item A, Item B) {
    Item lgst = (fabs(A) > fabs(B)) ? fabs(A) : fabs(B);
    return (fabs(A - B) / lgst < TOL); 
}

/**
 * @brief print the value of an Item
 * 
 */
#define ITEMshow(A) printf("%g", A)


/**
 * @brief Extracts an ITEM from the string pointed
 * to by src, and stores it in the Item pointed to
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
 * underlying double type represented in decimal.
 */
static inline size_t ITEMfromStr(char* src, Item* dest) {
    
    char* cur;

    //extract double
    Item val = 0.0;
    for (cur = src; isdigit(cur); cur++) {
        val = 10.0*val + (*cur - '0');
    }
    if (*cur = '.') *cur++;
    double power;
    for (power = 1.0; isdigit(*cur); cur++) {
        val = 10.0*val + (*cur - '0');
        power *= 10.0;
    }
    val = val / power;

    if (*cur == 'e' || *cur == 'E')
    {
        double sign = (*(++cur) == '-' ?  -1 : 1);
        if (*cur == '+' || *cur == '-') cur++;
        size_t exp;
        for (exp = 0; isdigit(*cur); cur++)
        {
            exp = 10 * exp + (*cur - '0');
        }
        if (sign == 1)
        {
            for (; exp > 0; exp--) val *= 10;
        }
        else
            for (; exp > 0; exp--) val /= 10;
    }

    //validate
    size_t len =  (size_t)(cur - src);
    if (len) *dest = val;
    return len;
}