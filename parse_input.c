#include "monty.h"

/**
 * rmv_newline - Remove new line
 * @s: String passed
 *
 * Return: String without new line
 */
char *rmv_newline(char *s)
{
	char *temp = NULL;
	size_t index;

	if (s == NULL)
		return (NULL);
	temp = malloc(sizeof(char) * strlen(s));
	if (temp == NULL)
		malloc_error();
	for (index = 0; index < strlen(s); index++)
	{
		if (index != strlen(s) - 1)
			temp[index] = s[index];
		else
			temp[index] = '\0';
	}
	free(s);
	return (temp);
}

/**
 * parse_input - Parse Inout from line
 * @str: String passed
 *
 * Return: Array of inputs
 */
char **parse_input(char *str)
{
	char **args = NULL, *temp, *s = NULL;
	int i = 0;

	if (str == NULL)
		return (NULL);
	args = malloc(sizeof(char *) * 3);
	if (args == NULL)
		malloc_error();
	s = rmv_newline(str), temp = strtok(s, " ");
	if (temp == NULL)
	{
		free(args), free(s);
		return (NULL);
	}
	while (i < 2 && temp != NULL)
	{
		args[i] = malloc(sizeof(char) * (strlen(temp) + 1));
		if (args[i] == NULL)
		{
			if (i != 0)
			{
				while (i > -1)
				{
					i--, free(args[i]);
				}
			}
			free(args), malloc_error();
		}
		strcpy(args[i], temp), i++;
		temp = strtok(NULL, " ");
	}
	args[i] = NULL;
	if (op_cmp(args[0]) && args[1] == NULL)
	{
		args[1] = NULL;
		args[2] = NULL;
	}
	free(s), s = NULL;
	return (args);
}


/**
 * check_digit - check if argument is digit
 * @s: String passed
 *
 * Return: 1 - if digit
 *         0 - otherwise
 */
int check_digit(char *s)
{
	if (s == NULL)
		argument_error();
	while (*s)
	{
		if (!isdigit(*s) && *s != '-' && *s != '+')
			return (0);
		s++;
	}
	return (1);
}
