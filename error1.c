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
