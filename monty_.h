#define  _POSIX_C_SOURCE 200809L
#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
/* #include <sys/types.h> */
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/** Global variable declarations */
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

/* monty opcodes */
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

/** Primary functions */
int main(int argc, char **argv);
void free_stack(stack_t **stack);
int start_stack(stack_t **stack);
int checks_mode(stack_t **stack);

int init_stack(stack_t **stack);
void free_tokens(void);
unsigned int token_arrlen(void);
int run_monty(FILE *script_fd);

/** Error handlers */
void setoperatoks_error(int err_code);
int malloc_error(void);
int noint_error(unsigned int line_number);
int shortstack_error(unsigned int line_number, char *site);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *info);
int pint_error(unsigned int line_number);
int usage_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);

#endif
