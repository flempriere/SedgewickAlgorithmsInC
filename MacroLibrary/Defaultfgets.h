/**
 * @file Defaultfgets.h
 * @author Felix Lempriere
 * @brief Provides a variant of fgets with default arguments.
 * @version 0.1
 * @date 2025-04-03
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

#include "MacroLibrary/DefaultArguments.h"
#include "MacroLibrary/Generic.h"
#include "MacroLibrary/Utility.h"

/**
 * @brief Macro for FGETS to parse default arguments. Requires the
 *
 */
#define FGETS(line, ...)                                    \
    GENERIC_IF(is_array(line),                              \
               CALL3_ND1(fgets, line, sizeof(line),         \
                         stdin __VA_OPT__(, ) __VA_ARGS__), \
               CALL3_ND1(fgets, line, 1, stdin __VA_OPT__(, ) __VA_ARGS__))
