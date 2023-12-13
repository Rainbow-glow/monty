#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* global variable */
extern char **operatoks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_stack(stack_t *stack;
void cm_push(stack_t **stack, unsigned int line_number);
void cm_pall(stack_t **stack, unsigned int line_number);
void cm_pint(stack_t **stack, unsigned int line_number);
void cm_pop(stack_t **stack, unsigned int line_number);
void cm_swap(stack_t **stack, unsigned int line_number);
void cm_add(stack_t **stack, unsigned int line_number);
void cm_nop(stack_t **stack, unsigned int line_number);
void cm_sub(stack_t **stack, unsigned int line_number);
void cm_div(stack_t **stack, unsigned int line_number);
void cm_mul(stack_t **stack, unsigned int line_number);
void cm_mod(stack_t **stack, unsigned int line_number);
void cm_pchar(stack_t **stack, unsigned int line_number);
void cm_pstr(stack_t **stack, unsigned int line_number);
void cm_rotl(stack_t **stack, unsigned int line_number);
void cm_rotr(stack_t **stack, unsigned int line_number);
void cm_queue(stack_t **stack, unsigned int line_number);
void cm_stack(stack_t **stack, unsigned int line_number);

/* error codes */
void setoperatoks_error(int err_code);
int malloc_error(void);
int noint_error(unsigned int line_number);

#endif
