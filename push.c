#include "monty.h"
#include <string.h>

/**
 * is_number - Checks if a string represents a valid integer number
 * @str: The string to check
 *
 * Return: 1 if the string represents a valid integer number, 0 otherwise
 */
int is_number(const char *str)
{

  int i;
  if (str == NULL || *str == '\0')
    return 0;

  i = 0;
  if (str[0] == '-' || str[0] == '+')
    i++;

  for (; str[i] != '\0'; i++)
    {
      if (str[i] < '0' || str[i] > '9')
	return 0;
    }

  return 1;
}

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    char *arg = strtok(NULL, " \n");

    if (!new_node || !arg || !is_number(arg))
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