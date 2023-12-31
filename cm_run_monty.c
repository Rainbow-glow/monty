#include "monty.h"
#include <string.h>

void free_tokens(void);
unsigned int token_arrlen(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_tokens - Frees the global operatoks array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (operatoks == NULL)
		return;

	for (i = 0; operatoks[i]; i++)
		free(operatoks[i]);

	free(operatoks);
}

/**
 * token_arrlen - Gets the length of current operatoks.
 *
 * Return: Length of current operatoks (as int).
 */
unsigned int token_arrlen(void)
{
	unsigned int toks_len = 0;

	while (operatoks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", cm_push},
		{"pall", cm_pall},
		{"pint", cm_pint},
		{"pop", cm_pop},
		{"swap", cm_swap},
		{"add", cm_add},
		{"nop", cm_nop},
		{"sub", cm_sub},
		{"div", cm_div},
		{"mul", cm_mul},
		{"mod", cm_mod},
		{"pchar", cm_pchar},
		{"pstr", cm_pstr},
		{"rotl", cm_rotl},
		{"rotr", cm_rotr},
		{"stack", cm_stack},
		{"queue", cm_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		operatoks = strtow(line, DELIMS);
		if (operatoks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (operatoks[0][0] == '#') /* comment line */
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(operatoks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(operatoks[0], line_number);
			free_tokens();
			break;
		}
		prev_tok_len = token_arrlen();
		op_func(&stack, line_number);
		if (token_arrlen() != prev_tok_len)
		{
			if (operatoks && operatoks[prev_tok_len])
				exit_status = atoi(operatoks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_status);
}
