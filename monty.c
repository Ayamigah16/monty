#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MODE_STACK 0

stack_t *stack_variable = NULL;
int mode = MODE_STACK;

/**
 * execute_monty_script - Executes a Monty script.
 * @script_file: Pointer to the Monty script file.
 */
void execute_monty_script(FILE *script_file)
{
	char *line = NULL;
	char *opcode;
	int value;
	size_t bufsize = 0;
	unsigned int line_number = 0;

	while (fgets(line, bufsize, script_file) != NULL)
	{
		line_number++;
		opcode = NULL;
		value = 0;

		if (parse_line(line, &opcode, &value) == 0)
		{
			process_opcode(opcode, &stack_variable, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: invalid instruction\n", line_number);
			free(line);
			free_stack(stack_variable);
			fclose(script_file);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
}

/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/* Rest of the code for executing Monty scripts */
/* ... */


/**
 * push_error - Handles an error when an invalid push command is encountered.
 * @line_number: The line number of the Monty script where the error occurred.
 */
void push_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	free_stack(stack_variable);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - Handles an error when malloc fails to allocate memory.
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * open_file_error - Handles an error when the specified file cannot be opened.
 * @filename: The name of the file that failed to open.
 */
void open_file_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * usage_error - Handles an error when the Monty program is not used properly.
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * parse_line - Parses a line from the Monty script into an opcode and a value.
 * @line: The line to parse.
 * @opcode: Pointer to store the extracted opcode.
 * @value: Pointer to store the extracted value.
 * Return: 0 if successful, -1 if there's an error parsing the line.
 */
int parse_line(char *line, char **opcode, int *value)
{
    char *token;
    token = strtok(line, " \t\n");

    if (token == NULL)
        return -1;
    
    *opcode = token;
    
    /* Check if there's a value provided */
    token = strtok(NULL, " \t\n");
    if (token != NULL)
    {
        if (sscanf(token, "%d", value) != 1)
	  return -1; /* Invalid value */
    }
    
    return 0; /* Successful parsing */
}

/**
 * process_opcode - Processes an opcode and calls the corresponding function.
 * @opcode: The opcode to process.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode.
 */
void process_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	opcode_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {"monty_div", monty_div},
        {"sub", sub},
        {"mul", mul},
        {"comments", comments},
        {"pchar", pchar},
        {"rotl", rotl},
        {"rotr", rotr},
        {"set_stack", set_stack},
        {"queue", queue}

        /* Add more opcodes here */
    };
    
    int num_opcodes = sizeof(opcodes) / sizeof(opcodes[0]);
    int i;
    for (i = 0; i < num_opcodes; i++)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, line_number);
            return;
        }
    }
    
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    free_stack(*stack);
    exit(EXIT_FAILURE);
}

/**
 * handle_error - Handles an error by printing an error message and freeing the stack.
 * @message: The error message to display.
 * @line_number: The line number where the error occurred.
 */
void handle_error(char *message, unsigned int line_number)
{
	fprintf(stderr, "L%u: %s\n", line_number, message);
	free_stack(stack_variable);
	exit(EXIT_FAILURE);
}