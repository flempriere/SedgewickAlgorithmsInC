/**
 * @file Utility.h
 * @author Felix Lempriere
 * @brief Header file for generic Utility Macros.
 *
 * @remark Any large set of macros for a common purpose should be spun off
 * into their own macro folder.
 * @version 0.1
 * @date 2025-03-23
 *
 * @copyright Copyright (c) 2025
 *
 */

 // Cast
 /**
 * @brief Make a cast explicit
 * 
 */
 #define CAST(T) (T)

// Stringification Macros

/**
 * @brief Stringify a token.
 *
 */
#define UTILITY_STRINGIFY(x) #x

/**
 * @brief Stringify token with argument replacement.
 *
 */
#define UTILITY_STRGY(x) MACRO_STRINGIFY(x)

// VA_ARG List featues

/**
 * @brief Submacro used by VA_ARG_LEN
 *
 */
#define UTILITY_VA_ARG_LEN0(_00, _01, _02, _03, _04, _05, _06, _07, _08, _09, \
                            _0A, _0B, _0C, _0D, _0F, _0E, _10, _11, _12, _13, \
                            _14, _15, _16, _17, _18, _19, _1A, _1B, _1C, _1D, \
                            _1F, _1E, ...)                                    \
    _1E    // returns the 31st element of the list

/**
 * @brief Returns the number of arguments in the variable list.
 *
 * @remark works for up to 31 elements. An empty list is treated
 * as one empty argument.
 */
#define UTILITY_VA_ARG_LEN(...)                                               \
    UTIITY_VA_ARG_LEN0(__VA_ARGS__, 0x1E, 0x1F, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, \
                       0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10,  \
                       0x0E, 0x0F, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07,  \
                       0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00)
