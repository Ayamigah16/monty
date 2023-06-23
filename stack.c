#include "monty.h"

/**
 * set_stack - Sets the format of the data to a stack (LIFO).
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode.
 */
void set_stack(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;
    /* No changes needed for stack mode */
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode.
 */
void queue(stack_t **stack, unsigned int line_number)
{

    /* Convert stack to queue */
    stack_t *temp;
    stack_t *last;

    /* Unused parameters */
    (void)stack;
    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    temp = *stack;
    last = *stack;

    while (last->next != NULL)
        last = last->next;

    *stack = (*stack)->next;
    (*stack)->prev = NULL;

    last->next = temp;
    temp->prev = last;
    temp->next = NULL;
}