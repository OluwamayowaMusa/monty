#include "monty.h"

/**
 * malloc_error - Error due to malloc
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}


/**
 * instruction_error - Error due to wrong instruction
 * @s: opcode passed
 */
void instruction_error(char *s)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, s);
	exit(EXIT_FAILURE);
}

/**
 * argument_error - Error due to argument
 */
void argument_error(void)
{
	fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
	exit(EXIT_FAILURE);
}


/**
 * pint_error - Error due to empty stack
 *
 */
void pint_error(void)
{
	fprintf(stderr, "L%d: can't pint, Stack empty\n", lineNumber);
	exit(EXIT_FAILURE);
}


/**
 * pop_error - Error due to pop
 *
 */
void pop_error(void)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", lineNumber);
	exit(EXIT_FAILURE);
}
