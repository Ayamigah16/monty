#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		if (temp->next)
			temp->next->prev = *stack;
		temp->prev = NULL;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
