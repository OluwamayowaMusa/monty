#include "monty.h"

/**
 * op_mul - Multiply the second top element of the stack with the top element
 * of the stack
 * @stack: Pointer to Pointer to stack (doubly linked list)
 * @data: 0(not important)
 *
 */
void op_mul(stack_t **stack, unsigned int __attribute__((unused)) data)
{
	stack_t *temp = NULL, *temp1 = NULL;
	int i = 0;

	temp = *stack;
	while (temp != NULL)
		temp = temp->next, i++;
	if (i < 2)
		mul_error();
	temp = *stack;
	temp1 = temp->next;
	temp1->n = temp1->n * temp->n;
	temp1->prev = NULL;
	free(*stack);
	*stack = temp1;
}


/**
 * op_mod - Modular division of the second and first element
 * @stack: Pointer to pointer to stack (doubly linked list);
 * @data: 0(not important)
 *
 */
void op_mod(stack_t **stack, unsigned int __attribute__((unused)) data)
{
	stack_t *temp = NULL, *temp1 = NULL;
	int i = 0;

	temp = *stack;
	while (temp != NULL)
		temp = temp->next, i++;
	if (i < 2)
		mod_error(1);
	temp = *stack;
	temp1 = temp->next;
	if (temp->n == 0)
		mod_error(0);
	temp1->n = temp1->n % temp->n;
	temp1->prev = NULL;
	free(*stack);
	*stack = temp1;
}
