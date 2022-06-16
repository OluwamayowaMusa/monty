#include "monty.h"

/**
 * op_push - Push a new element into the stack
 * @stack: pointer to pointer to stack doubly linked list
 * @data: Number to the be added to stack
 *
 */
void op_push(stack_t **stack, unsigned int data)
{
	stack_t *newStack = NULL;
	int val = (int)data;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	newStack = malloc(sizeof(stack_t));
	if (newStack == NULL)
		malloc_error();
	newStack->n = val;
	newStack->prev = NULL;
	if (*stack == NULL)
	{
		newStack->next = NULL;
		*stack = newStack;
		return;
	}
	newStack->next = *stack;
	(*stack)->prev = newStack;
	*stack = newStack;
	return;
}


/**
 * op_pall - Print all the values in the stack
 * @stack: pointer to pointer to stack doubly linked list
 * @data: 0(not important)
 *
 */
void op_pall(stack_t **stack, unsigned int __attribute__((unused)) data)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * op_cmp - Compares opcode
 * @s: Opcode passed
 *
 * Return: 1 - If present
 *         0 - Otherwsie
 */
int op_cmp(char *s)
{
	char *arr[] = {"pall", NULL};
	int i;

	for (i = 0; arr[i]; i++)
	{
		if (strcmp(s, arr[i]) == 0)
			return (1);
	}
	return (0);
}
