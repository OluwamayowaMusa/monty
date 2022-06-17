#include "monty.h"


int lineNumber = 1; /* Line Number (Global Variable) */

/**
 * main - Read Input file line by line
 * @argc: Argument count
 * @argv: Argument Vector
 *
 * Return: Always EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	stack_t *headStack = NULL;
	void (*func)(stack_t **, unsigned int);
	FILE *fp; /*File Pointer to file */
	char *line = NULL, **args = NULL;
	size_t n = 0;
	unsigned int ctrl = 1;
	int val;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r"); /* Open for reading */
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, fp) != -1)
	{
		args = parse_input(line), line = NULL;
		if (op_ctrl(args[0]) == 1)
			continue;
		else if (op_ctrl(args[0]) == 2)
		{
			ctrl = 7727;
			continue;
		}
		else if (op_ctrl(args[0]) == 3)
		{
			ctrl = 1;
			continue;
		}
		func = get_op_func(args[0]);
		if (func == NULL)
			instruction_error(args[0]);
		else if (op_cmp(args[0]))
			func(&headStack, 0);
		else if (!check_digit(args[1]))
			argument_error();
		else
			val = atoi(args[1]), func(&headStack, ((unsigned int)val * ctrl));
		lineNumber++, line = NULL;
		free_args(args), args = NULL;
	}
	free(line), free_stack(headStack), fclose(fp);
	return (EXIT_SUCCESS);
}
