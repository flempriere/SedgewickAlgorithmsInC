/**
 * @file NumberBit.h
 * @author Felix Lempriere
 * @brief Provides a variant of the Number Interface wrapping a Bool type
 * to provide Bit-like values.
 *
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */
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