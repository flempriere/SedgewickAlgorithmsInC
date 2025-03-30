// Interface for the number type, here we make it explicit
//  that this interface is for Integer numeric types.

/**
 * @brief localised typedef for number type being used
 *
 */
typedef unsigned int Number;
/**
 * @brief Generates a random number up to
 * MIN(RAND_MAX, INT_MAX)
 *
 * @return Number
 */
Number NUMBERrandom(Number upper_bound);