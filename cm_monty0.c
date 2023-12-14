#include "monty.h"

void cm_push(stack_t **stack, unsigned int line_number);
void cm_pall(stack_t **stack, unsigned int line_number);

/**
 * cm_push - pushes an element to the stack.
 * @stack: a pointer to the top node of the stack.
 * @line_number: line number in the file.
 */

void cm_push(stack_t **stack, unsigned int line_number)
{
	stack_t *dens, *new_ele;
	int x;

	new_ele = malloc(sizeof(stack_t));
	if (new_ele == NULL)
	{
		setoperatoks_error(malloc_error());
		return;
	}

	if (operatoks[1] == NULL)
	{
		setoperatoks_error(noint_error(line_number));
		return;
	}

	for (x = 0; operatoks[1][x]; x++)
	{
		if (operatoks[1][x] == '-' && x == 0)
			continue;
		if (operatoks[1][x] < '0' || operatoks[1][x] > 9)
		{
			setoperatoks_error(noint_error(line_number));
			return;
		}
	}

	new_ele->n = atoi(operatoks[1]);

	if (checks_mode(*stack) == STACK)
	{
		dens = (*stack)->next;
		new_ele->prev = *stack;
		new_ele->next = dens;
		if (dens)
			dens->prev = new_ele;
		(*stack)->next = new_ele;
	}
	else
	{
		dens = *stack;
		while (dens->next)
			dens = dens->next;
		new_ele->prev = dens;
		new_ele->next = NULL;
		dens->next = new_ele;
	}
}

/**
 * cm_pall - prints all the values on the stack, starting from the top.
 * @stack: a pointer to top mode node of the stack.
 * @line_number: the line number of the file.
 */

void cm_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *dens = (*stack)->next;

	while (dens)
	{
		printf("%d\n", dens->n);
		dens = dens->next;
	}
	(void)line_number;
}
