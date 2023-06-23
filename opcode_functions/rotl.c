#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
