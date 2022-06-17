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
	while (temp != NULL)
	{
		temp1 = temp->next;
		temp->next = temp2;
		temp2 = temp;
		temp2->prev = temp1;
		temp = temp1;
	}
	*stack = temp2;
}
