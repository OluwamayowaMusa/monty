#include "monty.h"

/**
 * swap_error - Error due to opcode swap
 *
 */
void swap_error(void)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
	exit(EXIT_FAILURE);
}


/**
 * add_error - Error due to opcode add
 *
 */
void add_error(void)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
	exit(EXIT_FAILURE);
}
