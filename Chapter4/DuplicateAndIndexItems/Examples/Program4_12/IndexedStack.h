/**
 * @file IndexedStack.h
 * @author Felix Lempriere
 * @brief Interface for a stack that contains elements indexed
 * from 0 to capacity - 1.
 *
 * We base the interface of the stack_v3.h interface with changes to
 * make clear that the expected input are indices (size_t).
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #include <stddef.h>

/**
 * @brief Initialises a stack for indices with largest index maxN-1.
 * 
 * @param capacity Maximum number of indices on the stack.
 *
 * @return true on success else
 * @return false.
 */
 bool INDEXEDSTACKinit(size_t maxN);

/**
 * @brief Returns the number of elements on the stack.
 * 
 * @return size_t number of elements on the stack.
 */
 size_t INDEXEDSTACKcount(void);

/**
 * @brief Pushes an index onto the stack.
 * 
 * @param idx index to put on the stack.
 *
 * @return true if successful else
 * @return false.
 */
 bool INDEXEDSTACKpush(size_t idx);

/**
 * @brief Pop and return the index ontop of the stack. 
 * 
 * @return size_t index on top of the stack, if the pop fails then the function
 * will @return SIZE_MAX.
 */
 size_t INDEXEDSTACKpop(void);

/**
 * @brief Prints an error msg on stderr. Should be used by
 * implementations to report error cases.
 * 
 * @param msg 
 */
 void INDEXEDSTACKerror(char* msg);