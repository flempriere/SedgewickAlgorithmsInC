/**
 * @file GenericMacro.h
 * @author Felix Lempriere
 * @brief General-purpose type generic macros.
 * @version 0.1
 * @date 2025-03-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

#include "Utility.h"

#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

// Assert types are compatible
#define static_assert_compatible(A, B, REASON)                            \
    static_assert(                                                        \
        _Generic((typeof(A)*) nullptr, typeof(B)*: true, default: false), \
        "Expected compatible types: " REASON " have " #A " and " #B "\n");

// Type Generic Conditionals

/**
 * @brief A simple type-generic conditional.
 *
 */
#define GENERIC_IF(COND, A, B) \
    _Generic((char(*)[1 + !!(COND)]) 0, char(*)[2]: (A), default: (B))

// IS_EVEN

/**
 * @brief check if x is even
 * @return true if even, else false
 */
#define IS_EVEN(x) !((x) % 2)

/**
 * @brief check if x is odd
 *
 */
#define IS_ODD(x) !(IS_EVEN(x))

// SWAP Macro

/**
 * @brief Swap A and B
 *
 */
#define SWAP(A, B)                                                       \
    do {                                                                 \
        auto SWAPA = (A);                                                \
        auto SWAPB = (B);                                                \
        static_assert_compatible(                                        \
            SWAPA, SWAPB, #A " and " #B "must have compatible types\n"); \
        auto SWAPtmp = SWAPA;                                            \
        SWAPA = SWAPB;                                                   \
        SWAPB = SWAPtmp;                                                 \
    } while (false)

// Type generic minimum

static inline float minf(float a, float b) { return a < b ? a : b; }

static inline double mind(double a, double b) { return a < b ? a : b; }

static inline long double minld(long double a, long double b) {
    return a < b ? a : b;
}

static inline int mini(int a, int b) { return a < b ? a : b; }

static inline unsigned int minu(unsigned int a, unsigned int b) {
    return a < b ? a : b;
}

static inline long minl(long a, long b) { return a < b ? a : b; }

static inline unsigned long minul(unsigned long a, unsigned long b) {
    return a < b ? a : b;
}

static inline long long minll(long long a, long long b) {
    return a < b ? a : b;
}

static inline unsigned long long minull(unsigned long long a,
                                        unsigned long long b) {
    return a < b ? a : b;
}

#define MIN(A, B)             \
    _Generic((A) + (B),       \
        float: minf,          \
        double: mind,         \
        long double: minld,   \
        int: mini,            \
        unsigned: minu,       \
        long: minl,           \
        unsigned long: minul, \
        long long: minll,     \
        unsigned long long: minull)(A, B)

/**
 ** @brief The minimum value for the type of @a X
 **/
#define MINVAL(X)                                    \
    _Generic((X),                                    \
        bool: CAST(bool) + 0,                        \
        char: CAST(char) + CHAR_MIN,                 \
        signed char: CAST(signed char) + SCHAR_MIN,  \
        unsigned char: CAST(unsigned char) + 0,      \
        signed short: CAST(signed short) + SHRT_MIN, \
        unsigned short: CAST(unsigned short) + 0,    \
        signed: INT_MIN,                             \
        unsigned: 0U,                                \
        signed long: LONG_MIN,                       \
        unsigned long: 0UL,                          \
        signed long long: LLONG_MIN,                 \
        unsigned long long: 0ULL,                    \
        float: -FLT_MAX,                             \
        double: -DBL_MAX,                            \
        long double: -LDBL_MAX)

/**
 ** @brief The minimum promoted value for @a XT, where @a XT
 ** can be an expression or a type name
 **
 ** So this is the minimum value when fed to an arithmetic
 ** operation such as @c +.
 **
 ** @remark Narrow types are promoted, usually to @c signed,
 ** or maybe to @c unsigned on rare architectures.
 **/

#define MINOF(XT)                    \
    _Generic(0 + (XT) + 0,           \
        signed: INT_MIN,             \
        unsigned: 0U,                \
        signed long: LONG_MIN,       \
        unsigned long: 0UL,          \
        signed long long: LLONG_MIN, \
        unsigned long long: 0ULL,    \
        float: -FLT_MAX,             \
        double: -DBL_MAX,            \
        long double: -LDBL_MAX)

// type generic maximum

static inline float maxf(float a, float b) { return a > b ? a : b; }

static inline double maxd(double a, double b) { return a > b ? a : b; }

static inline long double maxld(long double a, long double b) {
    return a > b ? a : b;
}

static inline int maxi(int a, int b) { return a > b ? a : b; }

static inline unsigned int maxu(unsigned int a, unsigned int b) {
    return a > b ? a : b;
}

static inline long maxl(long a, long b) { return a > b ? a : b; }

static inline unsigned long maxul(unsigned long a, unsigned long b) {
    return a > b ? a : b;
}

static inline long long maxll(long long a, long long b) {
    return a > b ? a : b;
}

static inline unsigned long long maxull(unsigned long long a,
                                        unsigned long long b) {
    return a > b ? a : b;
}

#define MAX(A, B)             \
    _Generic((A) + (B),       \
        float: maxf,          \
        double: maxd,         \
        long double: maxld,   \
        int: maxi,            \
        unsigned: maxu,       \
        long: maxl,           \
        unsigned long: maxul, \
        long long: maxll,     \
        unsigned long long: maxull)(A, B)

/**
 ** @brief The maximum value for the type of @a X
 **/
#define MAXVAL(X)                                         \
    _Generic((X),                                         \
        bool: CAST(bool) + 1,                             \
        char: CAST(char) + CHAR_MAX,                      \
        signed char: CAST(signed char) + SCHAR_MAX,       \
        unsigned char: CAST(unsigned char) + UCHAR_MAX,   \
        signed short: CAST(signed short) + SHRT_MAX,      \
        unsigned short: CAST(unsigned short) + USHRT_MAX, \
        signed: INT_MAX,                                  \
        unsigned: UINT_MAX,                               \
        signed long: LONG_MAX,                            \
        unsigned long: ULONG_MAX,                         \
        signed long long: LLONG_MAX,                      \
        unsigned long long: ULLONG_MAX,                   \
        float: FLT_MAX,                                   \
        double: DBL_MAX,                                  \
        long double: LDBL_MAX)

/**
 ** @brief The maximum promoted value for @a XT, where @a XT
 ** can be an expression or a type name
 **
 ** So this is the maximum value when fed to an arithmetic
 ** operation such as @c +.
 **
 ** @remark Narrow types are promoted, usually to @c signed,
 ** or maybe to @c unsigned on rare architectures.
 **/
#define MAXOF(XT)                       \
    _Generic(0 + (XT) + 0,              \
        signed: INT_MAX,                \
        unsigned: UINT_MAX,             \
        signed long: LONG_MAX,          \
        unsigned long: ULONG_MAX,       \
        signed long long: LLONG_MAX,    \
        unsigned long long: ULLONG_MAX, \
        float: FLT_MAX,                 \
        double: DBL_MAX,                \
        long double: LDBL_MAX)

// Generic power
#define pow(X, Y) \
    _Generic                                                      \
  (                                                             \
   (void (*)(typeof((X)+(Y)+0ULL), typeof((Y)+0ULL)))nullptr,   \
   /* Second argument is an integer. */                         \
   void (*)(float,              unsigned long long): pownf,     \
   void (*)(double,             unsigned long long): pown,      \
   void (*)(unsigned long long, unsigned long long): pown,      \
   void (*)(long double,        unsigned long long): pownl,     \
   /* Second argument is a floating point. */                   \
   void (*)(float,                           float): powf,      \
   void (*)(long double,                     float): powl,      \
   void (*)(long double,                    double): powl,      \
   void (*)(long double,               long double): powl,      \
   /* Second argument is a floating-point, and first */         \
   /* is double or integer.                          */         \
   default:                                          pow)       \
  ((X), (Y))

// generic snprintf

/**
 ** @brief Similar to `snprintf` but checks the buffer argument for
 ** the size.
 **
 ** To be able to do that check, the function has the size argument
 ** first and then the buffer, so the buffer can be specified as array
 ** parameter that depends on the that size.
 **/
[[maybe_unused]]
static inline int snprintf_swapped(size_t n, char s[restrict static n],
                                   char const* restrict form, ...) {
    va_list ap;
    va_start(ap);
    int ret = vsnprintf(s, n, form, ap);
    va_end(ap);
    return ret;
}

/**
 ** @brief A type-generic interface to `snprintf` that checks arguments.
 **
 ** We distinguish two cases. First if the first argument is `nullptr`
 ** the second argument is forced to `0` and the function `snprintf`
 ** is called. If it is not `nullptr` a function `snprintf_swapped`
 ** that just swaps the first two arguments is called. Because
 ** that function has the size argument first and then the buffer, the
 ** buffer can be specified as array parameter that depends on the
 ** that size.
 **/
#define GENERICsnprintf(S, N, F, ...)                                     \
    _Generic((S),                                                         \
        nullptr_t: snprintf(nullptr, GENERIC_IF(isice(N), (N), 0),        \
                            F __VA_OPT__(, ) __VA_ARGS__),                \
        default: snprintf_swapped(                                        \
                 _Generic((S), nullptr_t: 1, default: (N)),               \
                 _Generic((S), nullptr_t: (char[1]) { 0 }, default: (S)), \
                 (F) __VA_OPT__(, ) __VA_ARGS__))
