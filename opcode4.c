#include "monty.h"

/**
 * op_rotr - Rotates the stack to the bottom
 * @stack: Poinetr to poinetr to stack (doubly linked list)
 * @data: 0 (not important)
 *
 */
void op_rotr(stack_t **stack, unsigned int __attribute__((unused)) data)
{
	stack_t *temp = NULL, *temp1 = NULL, *temp2 = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	temp1 = temp->next;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	temp2 = temp1->prev;
	temp2->next = NULL;
	temp1->next = temp;
	temp->prev = temp1;
	temp1->prev = NULL;
	*stack = temp1;
}


/**
 * op_ctrl - Controls the way the data structure will behave(stack or queue)
 * @s: String passed
 *
 * Return: 1 - if a comment
 *         2 - if a queue
 *         3 - if a stack
 *         0 - otherwise
 */
int op_ctrl(char *s)
{
	if (*s == '#')
	{
		return (1);
	}
	else if (strcmp(s, "queue") == 0)
	{
		return (2);
	}
	else if (strcmp(s, "stack") == 0)
	{
		return (3);
	}
	return (0);
}
