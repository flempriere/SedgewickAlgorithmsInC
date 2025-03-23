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
#include "Utility.h"

#include <stdio.h>

#if NDEBUG
#    define TRACE_ON 0
#else
#    define TRACE_ON 1
#endif

/**
 * @brief A function to print a  list of values
 *
 * @remark This function is only to be called through the macro @TRACE_VALUES.
 */
static inline void TRACE_trace_values(FILE* s, char const func[static 1],
                                      char const line[static 1],
                                      char const expr[static 1],
                                      char const head[static 1], size_t len,
                                      long double const arr[len]) {
    fprintf(s, "%s:%s: (%s) %s %Lg", func, line, expr, head, arr[0]);
    for (size_t i = 1; i < len - 1; i++) { fprintf(s, " %Lg", arr[i]); }
    fputc('\n', s);
}

/**
 * @brief Submacro called by @MACRO_TRACE_VALUES
 *
 */
#define TRACE_TRACE_VALUES0(NARGS, EXPR, HEAD, ...)                           \
    do {                                                                      \
        if (TRACE_ON) {                                                       \
            if (NARGS > 1) {                                                  \
                TRACE_trace_values(stderr, __func__, UTILITY_STRGY(__LINE__), \
                                   "" EXPR "", "" HEAD "", N_ARGS,            \
                                   (long double const[NARGS]) {__VA_ARGS__}); \
            } else {                                                          \
                fprintf(stderr, "%s:", UTILITY_STRGY(__LINE__) ": %s\n",      \
                        __func__ HEAD);                                       \
            }                                                                 \
        }                                                                     \
    } while (false);

/**
 * @brief Traces a list of arguments without having to specify the type of
 * each argument.
 *
 * @remark This constructs a temporary array of long double, therefore implicit
 * conversion to that type is always guaranteed.
 */
#define TRACE_TRACE_VALUES(...)                                        \
    TRACE_TRACE_VALUES0(UTILITY_VA_ARG_LEN(__VA_ARGS__), #__VA_ARGS__, \
                        __VA_ARGS__)
                        