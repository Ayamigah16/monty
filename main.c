#define _GNU_SOURCE

#include "monty.h"
#include <stdio.h>

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *line_content = NULL;
    FILE *file;
    size_t size = 0;
    ssize_t read_line;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read_line = getline(&line_content, &size, file)) != -1)
    {
        bus.line_content = line_content;
        line_number++;

        execute(line_content, &stack, line_number, file);
    }

    free(line_content);
    free_stack(stack);
    fclose(file);

    return 0;
}
