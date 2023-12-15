#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
<<<<<<< HEAD
int start_stack(stack_t **stack);
=======
int init_stack(stack_t **stack);
>>>>>>> 442236c1a5ef5e4d167481556ae7b24967648f6a
int checks_mode(stack_t *stack);

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * checks_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int checks_mode(stack_t *stack)
{
<<<<<<< HEAD
	if ((stack)->n == STACK)
		return (STACK);
	else if ((stack)->n == QUEUE)
=======
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
>>>>>>> 442236c1a5ef5e4d167481556ae7b24967648f6a
		return (QUEUE);
	return (2);
}