#include "monty.h"

void setoperatoks_error(int err_code);
int malloc_error(void);
int noint_error(unsigned int line_number);

/**
 * setoperatoks_error - sets last element of operatoks to be an error code.
 * @err_code: integer with no argument stored as a string in operatoks.
 */

void setoperatoks_error(int err_code)
{
	int toks_len = 0;
	int i = 0;
	char *exits = NULL;
	char **nya_toks = NULL;

	toks_len = token_arrlen();
	nya_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!operatoks)
	{
		malloc_error();
		return;
	}

	while (i < toks_len)
	{
		nya_toks[i] = operatoks[i];
		i++;
	}

	exits = get_int(err_code);
	if (!exits)
	{
		free(nya_toks);
		malloc_error();
	}
	nya_toks[i++] = exits;
	nya_toks[i] = NULL;
	free(operatoks);
	operatoks = nya_toks;
}

/**
 * malloc_error - prints malloc error message.
 *
 * Return: prints EXIT_FAILURE.
 */

int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failure\n");
	return (EXIT_FAILURE);
}

/**
 * noint_error - prints invaild cm_push argument error.
 * @line_number: line number in Monty file.
 *
 * Return: EXIT_FAILURE.
 */

int noint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: push integer\n", line_number);
	return (EXIT_FAILURE);
}
