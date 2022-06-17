#include "monty.h"

/**
 * mod_error - Error due to opcode mop
 * @num: Error control
 *
 */
void mod_error(int num)
{
	if (num != 0)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		exit(EXIT_FAILURE);
	}
}


/**
 * pchar_error - Error due to the opcode pchar
 * @num: Error Control
 *
 */
void pchar_error(int num)
{
	if (num != 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
		exit(EXIT_FAILURE);
	}
}
