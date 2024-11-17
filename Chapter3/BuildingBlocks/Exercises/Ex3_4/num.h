//Interface for the number type

/**
 * @brief Localises reference to numeric type
 * 
 */
typedef int Number;

/**
 * @brief Generate a random integer between 0 and upper_bound - 1
 * by use of the modulus function.
 * 
 * @param upper_bound must be <= RAND_MAX
 * @return Number 
 */
Number randNumModulus(Number upper_bound);

/**
 * @brief Generate a random integer between 0
 * and upper_bound -1 by through generating
 * a double in the interval [0, 1) and expanding
 * to the interval [0, upper_bound) and truncating. 
 * 
 * @param upper_bound
 * @return Number 
 */
Number randNumTruncate(Number upper_bound);