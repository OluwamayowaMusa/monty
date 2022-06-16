#include "monty.h"

/**
 * free_args - Free memory assigned to array of args
 * @args: Array of args
 *
 */
void free_args(char **args)
{
	int i;

	for (i = 0; i < 3; i++)
		free(args[i]);
	free(args);
}


/**
 * free_stack - Free stack
 * @h: Pointer to stack(doubly linked list)
 *
 */
void free_stack(stack_t *h)
{
	stack_t *current = NULL;

	while (h != NULL)
	{
		current = h->next;
		free(h);
		h = current;
	}
}
