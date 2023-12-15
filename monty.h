#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* Global variabe declaration */
extern char **operatoks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Monty Opcodes */
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
void cm_pstr(stack_t **stack, unsigned int line_number);
void cm_pchar(stack_t **stack, unsigned int line_number);
void cm_rotl(stack_t **stack, unsigned int line_number);
void cm_rotr(stack_t **stack, unsigned int line_number);
void cm_queue(stack_t **stack, unsigned int line_number);
void cm_stack(stack_t **stack, unsigned int line_number);

/* primary functions */
int main(int argc, char **argv);
void free_stack(stack_t **stack);
void start_stack(stack_t **stack);
int checks_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arrlen(void);
int run_monty(FILE *script_fd);
char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);
char *getline(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);

/* Error handlers */
void setoperatoks_error(int err_code);
int malloc_error(void);
int noint_error(unsigned int line_number);
int shortstack_error(unsigned int line_number, char *site);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *info);
int pint_error(unsigned int line_number);
int usage_error(void);
int f_open_error(char *Fname);
int unknown_op_error(char *operacode, unsigned int line_number);

#endif
