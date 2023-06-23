#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
