#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
