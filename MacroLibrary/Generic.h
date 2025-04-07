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

#include "DefaultCalloc.h"
#include "TraceMacro.h"
#include "Utility.h"

#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

// Assert types are compatible
#define GENERICstatic_assert_compatible(A, B, REASON)                     \
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
#define SWAP(A, B)                                                         \
    do {                                                                   \
        auto const SWAPA = &(A);                                           \
        auto const SWAPB = &(B);                                           \
        GENERICstatic_assert_compatible(                                   \
            *SWAPA, *SWAPB, #A " and " #B "must have compatible types\n"); \
        auto SWAPtmp = *SWAPA;                                             \
        *SWAPA = *SWAPB;                                                   \
        *SWAPB = SWAPtmp;                                                  \
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

// generic snprintf

/**
 ** @brief Similar to `snprintf` but checks the buffer argument for
 ** the size.
 **
 ** To be able to do that check, the function has the size argument
 ** first and then the buffer, so the buffer can be specified as array
 ** parameter that depends on the that size.
 **/
static inline int snprintf_swapped(size_t n, char s[restrict static n],
                                   char const* restrict form, ...) {
    va_list ap;
    va_start(ap);
    int ret = vsnprintf(s, n, form, ap);
    va_end(ap);
    return ret;
}

/**
 * @brief Same as snprintf_swapped, but for vsnprintf.
 *
 */
static inline int vsnprintf_swapped(size_t n, char s[restrict static n],
                                    char const* restrict form, va_list arg) {
    return vsnprintf(s, n, form, arg);
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

/**
 * @brief Create a formatted string object.
 *
 * @param s formatted string specifier
 * @param ... format variables
 *
 * @remark This function allocates memory for the returned string, it is the
 * caller's responsibility to free the memory when they're done.
 *
 * @return char* - null-terminated string on success, else
 * @return nullptr.
 */
char* create_formatted_string(char s[static 1], ...) {
    va_list args1;
    va_start(args1);
    va_list args2;
    va_copy(args2, args1);

    // calculate the size needed for the buffer, and then ensure we allocate.
    int sz = vsnprintf(nullptr, 0, s, args1);
    if (sz < 0) {
        TRACE_VALUE("Invalid encoding in format specifier string", s);
        goto cleanup;
    }

    size_t buf_sz = CAST(size_t) sz + 1;
    char* buf = CALLOC(buf_sz, *buf);
    if (!buf) goto cleanup;

    va_end(args1);
    vsnprintf_swapped(buf_sz, buf, s, args2);
    va_end(args2);
    return buf;
cleanup:
    va_end(args1);
    va_end(args2);
    return nullptr;
}

// Type generic void comparison functions

static inline int cmpf(void const* a, void const* b) {
    float const af = *(CAST(float const*) a);
    float const bf = *(CAST(float const*) b);
    return (af > bf) - (af < bf);
}
static inline int cmpd(void const* a, void const* b) {
    double const ad = *(CAST(double const*) a);
    double const bd = *(CAST(double const*) b);
    return (ad > bd) - (ad < bd);
}
static inline int cmpld(void const* a, void const* b) {
    long double const ald = *(CAST(long double const*) a);
    long double const bld = *(CAST(long double const*) b);
    return (ald > bld) - (ald < bld);
}
static inline int cmpi(void const* a, void const* b) {
    int const ai = *(CAST(int const*) a);
    int const bi = *(CAST(int const*) b);
    return (ai > bi) - (ai < bi);
}
static inline int cmpu(void const* a, void const* b) {
    unsigned int const au = *(CAST(unsigned int const*) a);
    unsigned int const bu = *(CAST(unsigned int const*) b);
    return (au > bu) - (au < bu);
}
static inline int cmpl(void const* a, void const* b) {
    long const al = *(CAST(long const*) a);
    long const bl = *(CAST(long const*) b);
    return (al > bl) - (al < bl);
}
static inline int cmpul(void const* a, void const* b) {
    unsigned long const aul = *(CAST(unsigned long const*) a);
    unsigned long const bul = *(CAST(unsigned long const*) b);
    return (aul > bul) - (aul < bul);
}
static inline int cmpll(void const* a, void const* b) {
    long long const all = *(CAST(long long const*) a);
    long long const bll = *(CAST(long long const*) b);
    return (all > bll) - (all < bll);
}
static inline int cmpull(void const* a, void const* b) {
    unsigned long long const aull = *(CAST(unsigned long long const*) a);
    unsigned long long const bull = *(CAST(unsigned long long const*) b);
    return (aull > bull) - (aull < bull);
}
static inline int cmpc(void const* a, void const* b) {
    char const ac = *(CAST(char const*) a);
    char const bc = *(CAST(char const*) b);
    return (ac > bc) - (ac < bc);
}
static inline int cmpuc(void const* a, void const* b) {
    unsigned char const auc = *(CAST(unsigned char const*) a);
    unsigned char const buc = *(CAST(unsigned char const*) b);
    return (auc > buc) - (auc < buc);
}
static inline int cmpsc(void const* a, void const* b) {
    signed char const asc = *(CAST(signed char const*) a);
    signed char const bsc = *(CAST(signed char const*) b);
    return (asc > bsc) - (asc < bsc);
}
static inline int cmps(void const* a, void const* b) {
    short const as = *(CAST(short const*) a);
    short const bs = *(CAST(short const*) b);
    return (as > bs) - (as < bs);
}
static inline int cmpus(void const* a, void const* b) {
    unsigned short const aus = *(CAST(unsigned short const*) a);
    unsigned short const bus = *(CAST(unsigned short const*) b);
    return (aus > bus) - (aus < bus);
}

/**
 * @brief Returns a function pointer to a comparison function for the type of A.
 *
 * These comparison functions use the appropriate interface for a qsort
 * comparison function, i.e. their signature is `int cmp(const void* a, const
 * void* b)` and they return
 *  - a negative value if the first argument is less than the second,
 *  - zero if they are equal,
 *  - a positive value if the first argument is greater than the second.
 *
 * @return function pointer to a comparison function for the type of A.
 */
#define GET_CMP(A)                  \
    _Generic((A), float: cmpf,       \
        double: cmpd,               \
        long double: cmpld,         \
        int: cmpi,                  \
        unsigned: cmpu,             \
        long: cmpl,                 \
        unsigned long: cmpul,       \
        long long: cmpll,           \
        unsigned long long: cmpull, \
        char: cmpc,                 \
        unsigned char: cmpuc,       \
        signed char: cmpsc,         \
        short: cmps,                \
        unsigned short: cmpus)

// type generic print function
static inline void printf_float(void const* a) {
    printf("%.8f", *(CAST(float const*) a));
}
static inline void printf_double(void const* a) {
    printf("%.12lf", *(CAST(double const*) a));
}
static inline void printf_long_double(void const* a) {
    printf("%.20Lf", *(CAST(long double const*) a));
}
static inline void printf_int(void const* a) {
    printf("%d", *(CAST(int const*) a));
}
static inline void printf_unsigned_int(void const* a) {
    printf("%u", *(CAST(unsigned int const*) a));
}
static inline void printf_long(void const* a) {
    printf("%ld", *(CAST(long const*) a));
}
static inline void printf_unsigned_long(void const* a) {
    printf("%lu", *(CAST(unsigned long const*) a));
}
static inline void printf_long_long(void const* a) {
    printf("%lld", *(CAST(long long const*) a));
}
static inline void printf_unsigned_long_long(void const* a) {
    printf("%llu", *(CAST(unsigned long long const*) a));
}
static inline void printf_char(void const* a) {
    printf("%c", *(CAST(char const*) a));
}
static inline void printf_unsigned_char(void const* a) {
    printf("%c", *(CAST(unsigned char const*) a));
}
static inline void printf_signed_char(void const* a) {
    printf("%c", *(CAST(signed char const*) a));
}
static inline void printf_short(void const* a) {
    printf("%hd", *(CAST(short const*) a));
}
static inline void printf_unsigned_short(void const* a) {
    printf("%hu", *(CAST(unsigned short const*) a));
}
static inline void printf_void(void const* a) { printf("%p", a); }

/**
 * @brief Returns a function pointer to a print function for the type of A.
 * If no type is inferred the type is printed as a void pointer.
 *
 * @return function pointer to a print function for the type of A.
 */
#define GET_PRINT(A)                                   \
    _Generic((A),                                      \
        float: printf_float,                           \
        double: printf_double,                         \
        long double: printf_long_double,               \
        int: printf_int,                               \
        unsigned: printf_unsigned_int,                 \
        long: printf_long,                             \
        unsigned long: printf_unsigned_long,           \
        long long: printf_long_long,                   \
        unsigned long long: printf_unsigned_long_long, \
        char: printf_char,                             \
        unsigned char: printf_unsigned_char,           \
        signed char: printf_signed_char,               \
        short: printf_short,                           \
        unsigned short: printf_unsigned_short,         \
        default: printf_void)
