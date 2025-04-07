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
#define ID_IIIII(_01, _2, _3, _4, _5) _01, _2, _3, _4, _5

/* Macros to set default arguments */

/**
 * @brief Output the second argument, if any, or use DEF0 as the fallback
 * default value when no second argument is provided.
 *
 * @remark Error if more than two arguments are given.
 */
#define DEFAULT1(DEF0, ...) \
    ID_I##__VA_OPT__(Iplus_DEFAULT)(DEF0 __VA_OPT__(, ) __VA_ARGS__)

#define ID_IIplus_DEFAULT(_01, ...) ID_I(__VA_ARGS__)

/**
 * @brief Output comma separated arguments from the third position onwards.
 * Fill with defaults from the first two.
 */
#define DEFAULT2(DEF0, DEF1, ...) \
    ID_II##__VA_OPT__(Iplus_DEFAULT)(DEF0, DEF1 __VA_OPT__(, ) __VA_ARGS__)

#define ID_IIIplus_DEFAULT(DEF0, DEF1, _01, ...) \
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

// all arguments default

#define CALL1(FUNC, DEF0, ...) FUNC(DEFAULT1(DEF0, __VA_ARGS__))
#define CALL2(FUNC, DEF0, DEF1, ...) FUNC(DEFAULT2(DEF0, DEF1, __VA_ARGS__))
#define CALL3(FUNC, DEF0, DEF1, DEF2, ...) \
    FUNC(DEFAULT3(DEF0, DEF1, DEF2, __VA_ARGS__))
#define CALL4(FUNC, DEF0, DEF1, DEF2, DEF3, ...) \
    FUNC(DEFAULT4(DEF0, DEF1, DEF2, DEF3, __VA_ARGS__))

// must supply first argument
#define CALL2_ND1(FUNC, _0, DEF0, ...) FUNC(_0, DEFAULT1(DEF0, __VA_ARGS__))
#define CALL3_ND1(FUNC, _0, DEF0, DEF1, ...) \
    FUNC(_0, DEFAULT2(DEF0, DEF1, __VA_ARGS__))
#define CALL4_ND1(FUNC, _0, DEF0, DEF1, DEF2, ...) \
    FUNC(_0, DEFAULT3(DEF0, DEF1, DEF2, __VA_ARGS__))

// fixed first two arguments
#define CALL3_ND2(FUNC, _0, _1, DEF0, ...) \
    FUNC(_0, _1, DEFAULT1(DEF0, __VA_ARGS__))
#define CALL4_ND2(FUNC, _0, _1, DEF0, DEF1, ...) \
    FUNC(_0, _1, DEFAULT2(DEF0, DEF1, __VA_ARGS__))

// fixed first three arguments.
#define CALL4_ND3(FUNC, _0, _1, _2, DEF0, ...) \
    FUNC(_0, _1, _2, DEFAULT1(DEF0, __VA_ARGS__))

// fixed first 5 arguments
#define CALL5_ND4(FUNC, _0, _1, _2, _3, DEF0, ...) \
    FUNC(_0, _1, _2, _3, DEFAULT1(DEF0, __VA_ARGS__))


// Want to have same call structure but with optional vargs

#define IDOPT_()
#define IDOPT_I(_01, ...) _01 __VA_OPT__(, ) __VA_ARGS__
#define IDOPT_II(_01, _2, ...) ID_II(_01, _2)
#define IDOPT_III(_01, _2, _3, ...) ID_III(_01, _2, _3)
#define IDOPT_IIII(_01, _2, _3, _4, ...) ID_IIII(_01, _2, _3, _4)

/* Macros to set default arguments with optional extra vargs */

/**
 * @brief Output the second argument, if any, or DEF0 as a default.
 *
 * @remark Error if more than two arguments are given.
 */
#define DEFAULT1OPT(DEF0, ...) \
    IDOPT_I##__VA_OPT__(Iplus_DEFAULT)(DEF0 __VA_OPT__(, ) __VA_ARGS__)

#define IDOPT_IIplus_DEFAULT(_01, ...) IDOPT_I(__VA_ARGS__)

/**
 * @brief Output comma seperated arguments from the third position onwards.
 * Fill with defaults from the first two.
 */
#define DEFAULT2OPT(DEF0, DEF1, ...) \
    IDOPT_II##__VA_OPT__(Iplus_DEFAULT)(DEF0, DEF1 __VA_OPT__(, ) __VA_ARGS__)

#define IDOPT_IIIplus_DEFAULT(DEF0, DEF1, _01, ...) \
    DEFAULT1(DEF0, _01), DEFAULT1OPT(DEF1, __VA_ARGS__)

#define DEFAULT3OPT(DEF0, DEF1, DEF2, ...)           \
    IDOPT_III##__VA_OPT__(Iplus_DEFAULT)(DEF0, DEF1, \
                                         DEF2 __VA_OPT__(, ) __VA_ARGS__)

#define IDOPT_IIIIplus_DEFAULT(DEF0, DEF1, DEF2, _01, ...) \
    DEFAULT1(DEF0, _01), DEFAULT2OPT(DEF1, DEF2, __VA_ARGS__)

#define DEFAULT4OPT(DEF0, DEF1, DEF2, DEF3, ...)               \
    IDOPT_IIII##__VA_OPT__(Iplus_DEFAULTOPT)(DEF0, DEF1, DEF2, \
                                             DEF3 __VA_OPT__(, ) __VA_ARGS__)

#define IDOPT_IIIIIplus_DEFAULT(DEF0, DEF1, DEF2, DEF3, _01, ...) \
    DEFAULT1(DEF0, _01), DEFAULT3OPT(DEF1, DEF2, DEF3, __VA_ARGS__)

/* Macros for function calls with default
 * arguments */

// all arguments default with extra optionals

#define CALL1OPT(FUNC, DEF0, ...) FUNC(DEFAULT1OPT(DEF0, __VA_ARGS__))
#define CALL2OPT(FUNC, DEF0, DEF1, ...) \
    FUNC(DEFAULT2OPT(DEF0, DEF1, __VA_ARGS__))
#define CALL3OPT(FUNC, DEF0, DEF1, DEF2, ...) \
    FUNC(DEFAULT3OPT(DEF0, DEF1, DEF2, __VA_ARGS__))
#define CALL4OPT(FUNC, DEF0, DEF1, DEF2, DEF3, ...) \
    FUNC(DEFAULT4OPT(DEF0, DEF1, DEF2, DEF3, __VA_ARGS__))

// must supply first argument
#define CALL2_ND1OPT(FUNC, _0, DEF0, ...) \
    FUNC(_0, DEFAULT1OPT(DEF0, __VA_ARGS__))
#define CALL3_ND1OPT(FUNC, _0, DEF0, DEF1, ...) \
    FUNC(_0, DEFAULT2OPT(DEF0, DEF1, __VA_ARGS__))
#define CALL4_ND1OPT(FUNC, _0, DEF0, DEF1, DEF2, ...) \
    FUNC(_0, DEFAULT3OPT(DEF0, DEF1, DEF2, __VA_ARGS__))

// fixed first two arguments
#define CALL3_ND2OPT(FUNC, _0, _1, DEF0, ...) \
    FUNC(_0, _1, DEFAULT1OPT(DEF0, __VA_ARGS__))
#define CALL4_ND2OPT(FUNC, _0, _1, DEF0, DEF1, ...) \
    FUNC(_0, _1, DEFAULT2OPT(DEF0, DEF1, __VA_ARGS__))


