//Interface for the number type

/**
 * @brief localised typedef for number type being used
 * 
 */
typedef int Number;

/**
 * @brief largest number we can generate
 * 
 */
#define NUM_MAX INT_MAX

/**
 * @brief Generates a random number up to
 * MIN(RAND_MAX, INT_MAX)
 * 
 * @return Number 
 */
Number randNum();