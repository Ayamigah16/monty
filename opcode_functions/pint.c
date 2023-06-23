#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
