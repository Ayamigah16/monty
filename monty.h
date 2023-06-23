#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Data structures */

/**
 * struct stack_s - Doubly linked list representation of a stack
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous element of the stack (or NULL)
 * @next: Pointer to the next element of the stack (or NULL)
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct opcode_s - Struct opcode
 * @opcode: The opcode
 * @f: Function to handle the opcode
 */
typedef struct opcode_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} opcode_t;

/* Global variables */

extern stack_t *stack_variable;
extern int mode;

/* Function prototypes */

/* Main functions */
void execute_monty_script(FILE *script_file);
void free_stack(stack_t *stack);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void comments(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void set_stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/* Helper functions */
void push_error(unsigned int line_number);
void malloc_error(void);
void open_file_error(char *filename);
void usage_error(void);
int parse_line(char *line, char **opcode, int *value);
void process_opcode(char *opcode, stack_t **stack, unsigned int line_number);
void handle_error(char *message, unsigned int line_number);

#endif /* MONTY_H */
