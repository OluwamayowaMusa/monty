#include "monty.h"


int lineNumber = 0; /* Line Number (Global Variable) */
int ctrl = 0;

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
	int val;

	if (argc != 2)
		argv_error();
	fp = fopen(argv[1], "r"); /* Open for reading */
	if (fp == NULL)
		file_error(argv[1]);
	while (getline(&line, &n, fp) != -1)
	{
		lineNumber++, args = parse_input(line), line = NULL;
		if (args == NULL)
			continue;
		if (op_ctrl(args[0]) == 1)
		{
			free_args(args);
			continue;
		}
		else if (op_ctrl(args[0]) == 2)
		{
			ctrl = 1, free_args(args), args = NULL;
			continue;
		}
		else if (op_ctrl(args[0]) == 3)
		{
			ctrl = 0, free_args(args), args = NULL;
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
			val = atoi(args[1]), func(&headStack, ((unsigned int)val));
		line = NULL;
		free_args(args), args = NULL;
	}
	free(line), free_stack(headStack), fclose(fp);
	return (EXIT_SUCCESS);
}
