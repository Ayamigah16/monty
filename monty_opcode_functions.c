#include "monty.h"

/* Opcode Functions */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the pointer of the stack.
 * @value: Value to be pushed to the stack.
 */
void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    new_node->next = *stack;
    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the pointer of the stack.
 */
void pall(stack_t **stack)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void add(stack_t **stack, unsigned int line_number)
{
    int sum;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    sum = (*stack)->n + (*stack)->next->n;
    pop(stack, line_number);
    (*stack)->n = sum;
}

/**
 * nop - Doesn't do anything
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
