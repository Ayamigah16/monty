#include "monty.h"
/**
 * f_queue - prints the top
 * @stack: stack
 * @line_number: line_number
 * Return: no return
*/
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @stack: head of the stack
 * Return: no return
*/
void addqueue(stack_t **stack, int n)
{
	stack_t *new_node, *aux;

	aux = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
