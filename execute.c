#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @line_number: line number
* @file: poiner to monty file
* @line_content: line content
* Return: no return
*/
int execute(char *line_content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t opst[] = {
				{"push", push}, {"pall", pall}, {"pint", pint},
				{"pop", pop},
				{"swap", swap},
				{"add", add},
				{"nop", nop},
				{"sub", sub},
				{"div", monty_div},
				{"mul", mul},
				{"mod", mod},
				{"pchar", pchar},
				{"pstr", pstr},
				{"rotl", rotl},
				{"rotr", rotr},
				{"queue", queue},
				{"stack", stack_var},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(line_content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(line_content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
