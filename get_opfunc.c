#include "monty.h"

/**
 * get_op_func - Get op_code function
 * @s: string passed
 *
 * Return: Function related to string passed
 */
void (*get_op_func(char *s))(stack_t **, unsigned int)
{
	instruction_t array_func[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{NULL, NULL}
	};
	int i;

	if (s == NULL)
		return (NULL);
	for (i = 0; array_func[i].opcode; i++)
	{
		if (strcmp(s, array_func[i].opcode) == 0)
			return (array_func[i].f);
	}
	return (NULL);
}
