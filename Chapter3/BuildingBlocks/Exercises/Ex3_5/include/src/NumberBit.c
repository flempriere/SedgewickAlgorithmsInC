/**
 * @file NumberBit.c
 * @author Felix Lempriere
 * @brief Implements the Number interface for a Bit type using Bool.
 * @version 0.1
 * @date 2025-04-02
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "../NumberBit.h"

#include "MacroLibrary/Random.h"

Number NUMBERrandom(void) { return RANDUINT(2); }