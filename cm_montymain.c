#include "monty.h"
#include <sys/types.h>
#include <sys/fcntl.h>

char **operatoks = NULL; /* Global variable */

/**
 * main - the entry point for monty interpreter.
 * @argc: Argument count.
 * @argv: a pointer to an array of char pointer to an argument.
 *
 * Return: EXIT_SUCCESS on success, otherwise EXIT_FAILURE.
 */

int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_info = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit_info = run_monty(script_fd);
	fclose(script_fd);
	return (exit_info);
}
