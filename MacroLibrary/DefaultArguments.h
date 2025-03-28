/**
 * @file DefaultArguments.h
 * @author Felix Lempriere
 * @brief Set of Macros based on Modern C to allow for constructing
 * default argument versions of functions.
 * @version 0.1
 * @date 2025-03-28
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

/* Macros to output their given arguments */

#define ID_()
#define ID_I(_01) _01
#define ID_II(_01, _2) _01, _2
#define ID_III(_01, _2, _3) _01, _2, _3
#define ID_IIII(_01, _2, _3, _4) _01, _2, _3, _4

/* Macros to set default arguments */

/**
 * @brief Output the second argument, if any, or DEF0 as a default.
 *
 * @remark Error if more than two arguments are given.
 */
#define DEFAULT1(DEF0, ...) \
    ID_I##__VA_OPT__(Iplus_DEFAULT)(DEF0 __VA_OPT__(, ) __VA_ARGS__)

#define ID_IIplus_DEFAULT(_01, ...) ID_I(__VA_ARGS__)

/**
 * @brief Output comma seperated arguments from the third position onwards.
 * Fill with defaults from the first two.
 */
#define DEFAULT2(DEF0, DEF1, ...) \
    ID_II##__VA_OPT__(Iplus_DEFAULT)(DEF0, DEF1 __VA_OPT__(, ) __VA_ARGS__)

#define ID_IIIplus_DEFAULT(DEFO, DEF1, _01, ...) \
    DEFAULT1(DEF0, _01), DEFAULT1(DEF1, __VA_ARGS__)

#define DEFAULT3(DEF0, DEF1, DEF2, ...)           \
    ID_III##__VA_OPT__(Iplus_DEFAULT)(DEF0, DEF1, \
                                      DEF2 __VA_OPT__(, ) __VA_ARGS__)

#define ID_IIIIplus_DEFAULT(DEF0, DEF1, DEF2, _01, ...) \
    DEFAULT1(DEF0, _01), DEFAULT2(DEF1, DEF2, __VA_ARGS__)

#define DEFAULT4(DEF0, DEF1, DEF2, DEF3, ...)            \
    ID_IIII##__VA_OPT__(Iplus_DEFAULT)(DEF0, DEF1, DEF2, \
                                       DEF3 __VA_OPT__(, ) __VA_ARGS__)

#define ID_IIIIIplus_DEFAULT(DEF0, DEF1, DEF2, DEF3, _01, ...) \
    DEFAULT1(DEF0, _01), DEFAULT3(DEF1, DEF2, DEF3, __VA_ARGS__)

/* Macros for function calls with default
 * arguments */

#define CALL1(FUNC, DEF0, ...) FUNC(DEFAULT1(DEF0, __VA_ARGS__))
#define CALL2(FUNC, DEF0, DEF1, ...) FUNC(DEFAULT2(DEF0, DEF1, __VA_ARGS__))
#define CALL3(FUNC, DEF0, DEF1, DEF2, ...) \
    FUNC(DEFAULT3(DEF0, DEF1, DEF2, __VA_ARGS__))
#define CALL4(FUNC, DEF0, DEF1, DEF2, DEF3, ...) \
    FUNC(DEFAULT4(DEF0, DEF1, DEF2, DEF3, __VA_ARGS__))
