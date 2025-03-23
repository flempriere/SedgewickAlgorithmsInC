/**
 * @file Random.h
 * @author Felix Lempriere
 * @brief File containing Macros and functions related to random numbers.
 * @version 0.1
 * @date 2025-03-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 /**
 * @brief generates a random number between 0 and @N
 * @param N unsigned integer <= RAND_MAX
 *
 */
#define RAND_SIZE_T(N) (CAST(size_t) rand() % (N))