/**
 * @file NumberShort.c
 * @author Felix Lempriere
 * @brief Implementation of the Number interface with an underlying short type.
 * @version 0.1
 * @date 2025-04-02
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "../NumberShort.h"

#include "MacroLibrary/Random.h"
#include "MacroLibrary/Utility.h"

Number NUMBERrandom(Number const ub) { return CAST(Number) RANDUINT(ub); }