#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Data Structures */

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value of the node
 * @prev: Pointer to the previous element in the stack (or queue)
 * @next: Pointer to the next element in the stack (or queue)
 *
 * Description: Doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its corresponding function
 * @opcode: The opcode
 * @f: Pointer to the function that handles the opcode
 *
 * Description: Opcode and its function for stack manipulation
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function Prototypes */

/* Opcode Functions */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number)
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
