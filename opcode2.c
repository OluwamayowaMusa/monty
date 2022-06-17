#include "monty.h"

/**
 * op_swap - Swap the top two elements of the stack
 * @stack: Pointer to pointer to stack (doubly linked list)
 * @data: 0(not important)
 *
 */
void op_swap(stack_t **stack, unsigned int __attribute__((unused)) data)
{
	stack_t *temp = NULL, *temp1 = NULL, *temp2 = NULL;
	int i = 0;

	temp = *stack;
	while (temp != NULL)
		temp = temp->next, i++;
	if (i < 2)
		swap_error();
	temp = *stack;
	temp1 = temp->next;
	temp2 = temp1->next;
	temp->next = temp2;
	if (temp2 != NULL)
		temp2->prev = temp;
	temp1->next = temp;
	temp->prev = temp1;
	temp1->prev = NULL;
	*stack = temp1;
}
