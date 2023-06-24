#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: stack
 * @line_number: line_number
 * Return: no return
*/
void add(stack_t **stack, unsigned int line_number)
{
stack_t *h;
int len = 0, aux;

h = *stack;
while (h)
{
h = h->next;
len++;
}

if (len < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
fclose(bus.file);
free(bus.line_content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
h = *stack;
aux = h->n + h->next->n;
h->next->n = aux;
*stack = h->next;
free(h);
}
