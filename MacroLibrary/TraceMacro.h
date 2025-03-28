/**
 * @file TraceMacro.h
 * @author Felix Lempriere
 * @brief A set of Macros for providing debug output. Based on those provided
 * by Jens Gudstedt's Modern C.
 * @version 0.1
 * @date 2025-03-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

#include "Utility.h"

#include <stdio.h>

#if NDEBUG
#    define TRACE_ON 0
#else
#    define TRACE_ON 1
#endif

/**
 ** @brief Returns a format that is suitable for @c fprintf
 **
 ** @return The argument @a F must be a string literal,
 ** so the return value will also be one.
 **
 **/
#define TRACE_FORMAT(F, X)                  \
    _Generic((X) + 0LL,                     \
        unsigned long long: "" F " %llu\n", \
        long long: "" F " %lld\n",          \
        float: "" F " %.8f\n",              \
        double: "" F " %.12f\n",            \
        long double: "" F " %.20Lf\n",      \
        default: "" F " %p\n")

/**
 ** @brief Returns a value that forcibly can be interpreted as
 ** pointer value
 **
 ** That is, any pointer will be returned as such, but other
 ** arithmetic values will result in a @c nullptr.
 **/
#define TRACE_POINTER(X)             \
    _Generic((X) + 0LL,              \
        unsigned long long: nullptr, \
        long long: nullptr,          \
        float: nullptr,              \
        double: nullptr,             \
        long double: nullptr,        \
        default: (X))

/**
 ** @brief Returns a value that is promoted either to a wide
 ** integer, to a floating point, or to a @c void* if @a X is a
 ** pointer
 **/
#define TRACE_CONVERT(X)               \
    _Generic((X) + 0LL,                \
        unsigned long long: (X) + 0LL, \
        long long: (X) + 0LL,          \
        float: (X) + 0LL,              \
        double: (X) + 0LL,             \
        long double: (X) + 0LL,        \
        default: ((void*) { nullptr } = TRACE_POINTER(X)))

/**
 ** @brief Traces a value without having to specify a format
 **
 ** This variant works correctly with non-void pointers.
 **
 ** The formats are tunable by changing the specifiers in
 ** ::TRACE_FORMAT.
 **/
#define TRACE_VALUE(F, X)                                                  \
    do {                                                                   \
        if (TRACE_ON)                                                      \
            fprintf(stderr, TRACE_FORMAT("%s:" UTILITY_STRGY(__LINE__) ": " F, X), \
                    __func__, TRACE_CONVERT(X));                           \
    } while (false)