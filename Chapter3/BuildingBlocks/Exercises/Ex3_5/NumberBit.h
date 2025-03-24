// Interface for the number type
// utilises C23 for bool, otherwise use _Bool or <stdbool.h>
#pragma once
/**
 * @brief Bit type support is
 * implemented by using the bool type.
 *
 * In this regard, it captures the behaviour of a bit,
 * not the memory footprint.
 */
typedef bool Number;

/**
 * @brief Generates a random bit value
 *
 * @return 0 or 1
 */
Number NUMBERrandom(void);