#include "monty.h"
/**
 * swap - adds the top two elements of the stack.
 * @stack: stack stack
 * @counter: line_number
 * Return: no return
*/
void swap(stack_t **stack, unsigned int counter)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}

