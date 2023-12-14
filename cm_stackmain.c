#include "monty.h"

void free_stack(stack_t **stack);
int start_stack(stack_t **stack);
int checks_mode(stack_t **stack);

/**
 * start_stack - Initiates a stack_t list with stack and queue nodes.
 * @stack: A pointer to an uninitiated stack.
 *
 * Return: EXIT_FAILURE if an error occurs, otherwise EXIT_SUCCESS.
 */
int start_stack(stack_t **stack)
{
	stack_t *p;

	p = malloc(sizeof(stack_t));
	if (p == NULL)
	{
		return (EXIT_FAILURE);
	}

	p->n = STACK;
	p->prev = NULL;
	p->next = NULL;

	*stack = p;

	return (EXIT_SUCCESS);
}

/**
 * checks_mode - Checks if the list is in stack or queue mode.
 * @stack: A pointer to an uninitiated stack.
 *
 * Return: STACK (0) in stack mode, QUEUE (1) in queue mode, otherwise 2.
 */
int checks_mode(stack_t **stack)
{
	if ((*stack)->n == STACK)
		return (STACK);
	else if ((*stack)->n == QUEUE)
		return (QUEUE);
	else
		return (2);
}

/**
 * free_stack - Frees stack_t list.
 * @stack: A pointer to the stack or queue list.
 */
void free_stack(stack_t **stack)
{
	stack_t *head = *stack;

	while (*stack)
	{
		head = (*stack)->next;
		free(*stack);
		*stack = head;
	}
}