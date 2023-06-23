#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void rotr(stack_t **stack, unsigned int line_number)
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
	*stack = tmp;
	tmp = tmp->prev;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
