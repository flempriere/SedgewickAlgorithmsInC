//Interface for the number type
//utilises C23 for bool, otherwise use _Bool or <stdbool.h>

/**
 * @brief Bit type support is
 * implemented by using the bool type.
 * 
 */
typedef bool Number;

/**
 * @brief Generates a random bit value
 * 
 * @return 0 or 1
 */
Number randNum(void);