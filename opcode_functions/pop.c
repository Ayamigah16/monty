#include "monty.h"

/**
* pop - removes the top element of the stack
* @stack: Double pointer to the stack
* @line_number: Line number of the opcode
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;

    if (*stack)
        (*stack)->prev = NULL;

    free(temp);
}
