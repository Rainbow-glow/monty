#include "monty.h"

int shortstack_error(unsigned int line_number, char *site);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pchar_error(unsigned int line_number, car *info);
int pint_error(unsigned int line_number);

/**
 * shortstack_error - prints math function error message in monty.
 * @line_number: the line number of the monty file.
 * @site: where the error occurred.
 *
 * Return: EXIT_FAILURE.
 */

int shortstack_error(unsigned int line_number, char *site)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, site);
	return (EXIT_FAILURE);
}

/**
 * div_error - prints division error message for division by 0 in monty.
 * @line_number: the line number of the monty file.
 *
 * Return: EXIT_FAILURE.
 */

int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pop_error - prints pop error message for empty stacks in monty.
 * @line_number: the line number of the monty file.
 *
 * Return: EXIT_FAILURE.
 */

int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - prints pchar error message for empty stacks
 *		and non-character values in monty.
 * @info: corresponding error message to be printed.
 * @line_number: the line number of the monty file.
 *
 * Return: EXIT_FAILURE.
 */

int pchar_error(unsigned int line_number, char *info)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, info);
	return (EXIT_FAILURE);
}

/**
 * pint_error - prints pint error message for empty stacks in monty.
 * @line_number: the line number of the monty file.
 *
 * Return: EXIT_FAILURE.
 */

int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, empty stack\n", line_number);
	return (EXIT_FAILURE);
}

