#include "monty.h"

int usage_error(void);
int f_open_error(char *Fname);
int unknown_op_error(char *operacode, unsigned int line_number);

/**
 * usage_error - prints usage error messages.
 *
 * Return: EXIT_FAILURE
 */

int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - prints opening of file error messages with filename.
 * @Fname: the file name that failed to open.
 *
 * Return: EXIT_FAILURE
 */

int f_open_error(char *Fname)
{
	fprintf(stderr, "Error: can't open file %s\n", Fname);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - prints unknown instruction error messages.
 * @operacode: opcode where the error occurred.
 * @line_number: the line number in monty file.
 *
 * Return: EXIT_FAILURE.
 */

int unknown_op_error(char *operacode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, operacode);
	return (EXIT_FAILURE);
}

