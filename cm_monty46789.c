#include "monty.h"

void cm_add(stack_t **stack, unsigned int line_number);
void cm_sub(stack_t **stack, unsigned int line_number);
void cm_div(stack_t **stack, unsigned int line_number);
void cm_mul(stack_t **stack, unsigned int line_number);
void cm_mod(stack_t **stack, unsigned int line_number);

/**
 * cm_add - adds the top two elements of the stack.
 * @stack: a pointer to the top mode node of the stack list.
 * @line_number: the line number of a monty file.
 *
 * Description: The result is stored in the second top element of the stack,
 *		and the top element is removed.
 */

void cm_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setoperatoks_error(shortstack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	cm_pop(stack, line_number);
}

/**
 * cm_sub - subtracts the top element of the stack
 *	from the second top element of the stack.
 * @stack: a pointer to the top mode node of the stack list.
 * @line_number: the line number of a monty file.
 *
 * Description: The result is stored in the second top element of the stack,
 *		and the top element is removed.
 */

void cm_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setoperatoks_errror(shortstack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	cm_pop(stack, line_number);
}

/**
 * cm_div - divides the second top element by the top element of the stack.
 * @stack: a pointer to the top mode node of the stack list.
 * @line_number: the line number of a monty file.
 *
 * Description: The result is stored in the second top element of the stack,
 *		and the top element is removed.
 */

void cm_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setoperatoks_errror(shortstack_error(line_number, "div"));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	cm_pop(stack, line_number);
}

/**
 * cm_mul - multiplies the second top element with the top element of the stack
 * @stack: a pointer to the top mode node of the stack list.
 * @line_number: the line number of a monty file.
 *
 * Description: The result is stored in the second top element of the stack,
 *		and the top element is removed.
 */

void cm_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setoperatoks_errror(shortstack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	cm_pop(stack, line_number);
}

/**
 * cm_mod - computes the rest of the division of the second top element
 *	of the stack by the top element of the stack.
 * @stack: a pointer to the top mode node of the stack list.
 * @line_number: the line number of a monty file.
 *
 * Description: The result is stored in the second top element of the stack,
 *		and the top element is removed.
 */

void cm_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setoperatoks_errror(shortstack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		setoperatoks_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	cm_pop(stack, line_number);
}

