#include "monty.h"

/**
  * pall - prints all the values on the stack, starting from the top of the stack
  * @stack: Double pointer to the stack
  * @line_number: Line number of the opcode
 */

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
