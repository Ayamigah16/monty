#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    char *arg = strtok(NULL, " \n");

    if (!new_node || !arg || !is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(arg);
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}
