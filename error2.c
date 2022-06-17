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


/**
 * sub_error - Error due to opcode sub
 *
 */
void sub_error(void)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
	exit(EXIT_FAILURE);
}


/**
 * div_error - Error due to opcode div
 * @num: Error control
 *
 */
void div_error(int num)
{
	if (num != 0)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		exit(EXIT_FAILURE);
	}
}
