/**
 * @file Statistics.h
 * @author Felix Lempriere
 * @brief A header containing useful functions and macros for calculating and
 * displaying statistics.
 * @version 0.1
 * @date 2025-03-30
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

#include "DefaultArguments.h"
#include "Utility.h"
#include "stdarg.h"

#include <stddef.h>
#include <stdio.h>
#include <tgmath.h>

/**
 * @brief Structure containing the statistical moments of a distribution.
 *
 */
typedef struct STATSmoments {
    double m1;
    double m2;
} STATSmoments;

/**
 * @brief Structure containing tthe statistical measures of a distribution
 * in this case meaning avg and std_dev. Leaving room to add skew and kurtosis.
 *
 */
typedef struct STATSmeasures {
    double avg;
    double std_dev;
} STATSmeasures;

/**
 * @brief Calculate the standard deviation given the first and second moment.
 *
 * @param m1 - first moment
 * @param m2 - second moment
 *
 * @return standard deviation.
 */
#define STD_DEV(m1, m2) \
    sqrt(m2 - m1 * m1)    // #TODO: replace with type generic macro

/**
 * @brief Converts a STATSmeasures struct into the equivalent STATSmoments.
 *
 * @param sm
 * @return STATSmoments
 */
static inline STATSmoments STATSmeasures_to_moments(STATSmeasures const sm) {
    return CAST(STATSmoments){ .m1 = sm.avg,
                               .m2 = sm.std_dev * sm.std_dev + sm.avg * sm.avg };
}

/**
 * @brief Calculates the difference between two STATSmoments. (sm1 - sm2).
 *
 * @param sm1
 * @param sm2
 * @return STATSmoments
 */
static inline STATSmoments STATSmoments_difference(STATSmoments const sm1,
                                                   STATSmoments const sm2) {
    return CAST(STATSmoments){ .m1 = sm1.m1 - sm2.m1, .m2 = sm1.m2 - sm2.m2 };
}

/**
 * @brief Converts a STATSmoments struct into the equivalent STATSmeasures
 *
 * @param sm
 * @return STATSmeasures
 */
static inline STATSmeasures STATSmoments_to_measures(STATSmoments sm) {
    return CAST(STATSmeasures){ .avg = sm.m1,
                                .std_dev = sqrt(sm.m2 - sm.m1 * sm.m1) };
}

/**
 * @brief Calculates the difference between two STATSmeasures (sm1 - sm2).
 *
 * @param sm1
 * @param sm2
 * @return STATSmoments
 */
static inline STATSmeasures STATSmeasures_difference(STATSmeasures const sm1,
                                                     STATSmeasures const sm2) {
    return CAST(STATSmeasures){ .avg = sm1.avg - sm2.avg,
                                .std_dev = sm1.std_dev - sm2.std_dev };
}

STATSmeasures STATScalculate_statistics(double f(void), size_t n) {
    register double m1 = 0.0;
    register double m2 = 0.0;

    for (register size_t i = 0; i < n; i++) {
        register double x = f();
        m1 += (x) / CAST(double) n;
        m2 += (x * x) / CAST(double) n;
    }
    return CAST(STATSmeasures){ .avg = m1, .std_dev = STD_DEV(m1, m2) };
}

STATSmeasures STATScalculate_statistics_I(double f(double), size_t n,
                                          double arg) {
    register double m1 = 0.0;
    register double m2 = 0.0;

    for (register size_t i = 0; i < n; i++) {
        register double x = f(arg);
        m1 += (x) / CAST(double) n;
        m2 += (x * x) / CAST(double) n;
    }
    return CAST(STATSmeasures){ .avg = m1, .std_dev = STD_DEV(m1, m2) };
}

#define STATScalculate_statistics(f, n, ...) \
    (STATScalculate_statistics##__VA_OPT__(_I))(f, n __VA_OPT__(, ) __VA_ARGS__)

/**
 * @brief Print out statistical moments with an optional header string *s.
 *
 * @param s optional header string with format specifiers, use nullptr if not
 * printing.
 * @param sm
 */
void STATSmoments_print(STATSmoments const sm, char const* const s, ...) {
    if (s) {
        va_list ap;
        va_start(ap);
        vprintf(s, ap);
        putchar('\n');
        va_end(ap);
    }
    printf("       First moment: %f\n", sm.m1);
    printf("      Second moment: %f\n", sm.m2);
}

/**
 * @brief Print out statistical measures with an optional header string *s.
 *
 * @param s optional header string with format specifiers, use nullptr if not
 * printing.
 * @param sm
 */
void STATSmeasures_print(STATSmeasures const sm, char const* const s, ...) {
    if (s) {
        va_list ap;
        va_start(ap);
        vprintf(s, ap);
        putchar('\n');
        va_end(ap);
    }
    printf("            Average: %f\n", sm.avg);
    printf(" Standard Deviation: %f\n", sm.std_dev);
}

/**
 * @brief Default arguments version of STATSmoments_to_print, by default the
 * optional header string is set to nullptr.
 *
 */
#define STATSmoments_print(sm, ...) \
    CALL2_ND1OPT(STATSmoments_print, sm, nullptr __VA_OPT__(, ) __VA_ARGS__)

/**
 * @brief Default arguments version of STATSmoments_to_print, by default the
 * optional header string is set to nullptr.
 *
 */
#define STATSmeasures_print(sm, ...) \
    CALL2_ND1OPT(STATSmeasures_print, sm, nullptr __VA_OPT__(, ) __VA_ARGS__)

/**
 * @brief Type generic interface for printing statistical summaries.
 *
 *
 *@remark the CAST(type) {0} in the second _Generic ensure that all codepaths
 * are syntacically valid, but are unreachable. (If we used pointers we could
 * make a dummy function and cast to the (void *) to generate linkage errors at
 * compile time.)
 */

#define STATSsummary_print(sm, ...)                                            \
    _Generic(sm,                                                               \
        STATSmoments: STATSmoments_print(_Generic(sm,                          \
                                             STATSmoments: sm,                 \
                                             default: CAST(STATSmoments){ 0 }) \
                                             __VA_OPT__(, ) __VA_ARGS__),      \
        STATSmeasures: STATSmeasures_print(                                    \
                 _Generic(sm,                                                  \
                     STATSmoments: CAST(STATSmoments){ 0 },                    \
                     STATSmeasures: sm) __VA_OPT__(, ) __VA_ARGS__))
