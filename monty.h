#ifndef MONTY_H
#define MONTY_H

/* Header Files */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - Doubly linked list representation of a stack
 * @n: Integer
 * @prev: points to the previous element of statck
 * @next: points to the next element of stack
 *
 * Desscription: Doubly linked list node structure
 * for stack, LIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: The Opcode(Operations code)
 * @f: function to handle the opcode
 *
 * Description: Opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern int lineNumber; /* line number for file */
extern int ctrl; /* Control the operation of stack(if stack or queue */

/* FUNCTION PROTOTYPES */

/* INPUT FUNCTIONS */
char **parse_input(char *str);
char *rmv_newline(char *s);
int check_digit(char *s);

/* ERROR FUNCTIONS */
void argv_error(void);
void file_error(char *s);
void malloc_error(void);
void instruction_error(char *s);
void argument_error(void);
void pint_error(void);
void pop_error(void);
void swap_error(void);
void add_error(void);
void sub_error(void);
void div_error(int num);
void mul_error(void);
void mod_error(int num);
void pchar_error(int num);

/* MEMORY LEAKS FUNCTIONS*/
void free_args(char **args);
void free_stack(stack_t *h);

/* OPCODE FUNCTIONS */
void op_push(stack_t **stack, unsigned int data);
void op_pall(stack_t **stack, unsigned int data);
void op_pint(stack_t **stack, unsigned int data);
void op_pop(stack_t **stack, unsigned int data);
void op_swap(stack_t **stack, unsigned int data);
void op_add(stack_t **stack, unsigned int data);
void op_nop(stack_t **stack, unsigned int data);
void op_sub(stack_t **stack, unsigned int data);
void op_div(stack_t **stack, unsigned int data);
void op_mul(stack_t **stack, unsigned int data);
void op_mod(stack_t **stack, unsigned int data);
void op_pchar(stack_t **stack, unsigned int data);
void op_pstr(stack_t **stack, unsigned int data);
void op_rotl(stack_t **stack, unsigned int data);
void op_rotr(stack_t **stack, unsigned int data);
int op_cmp(char *s);
int op_ctrl(char *s);


/* GET OPCODE FUNCTIONS */
void (*get_op_func(char *s))(stack_t **, unsigned int);

#endif /* MONTY_H */
