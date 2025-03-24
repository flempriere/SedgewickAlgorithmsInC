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

#include "TraceMacro.h"

/**
 * @brief check if x is even
 * @return true if even, else false
 */
#define IS_EVEN(x) !((x) % 2)

/**
 * @brief Swap A and B
 *
 */
#define SWAP(A, B)          \
    do {                    \
        auto _A = (A);      \
        auto _B = (B);      \
        typeof(_A) _t = _A; \
        _A = _B;            \
        _B = _t;            \
    } while (false)

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

static inline float maxf(float a, float b) { return a < b ? a : b; }

static inline double maxd(double a, double b) { return a < b ? a : b; }

static inline long double maxld(long double a, long double b) {
    return a < b ? a : b;
}

static inline int maxi(int a, int b) { return a < b ? a : b; }

static inline unsigned int maxu(unsigned int a, unsigned int b) {
    return a < b ? a : b;
}

static inline long maxl(long a, long b) { return a < b ? a : b; }

static inline unsigned long maxul(unsigned long a, unsigned long b) {
    return a < b ? a : b;
}

static inline long long maxll(long long a, long long b) {
    return a < b ? a : b;
}

static inline unsigned long long maxull(unsigned long long a,
                                        unsigned long long b) {
    return a < b ? a : b;
}
