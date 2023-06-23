#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *script_file;
    
    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }
    
    script_file = fopen(argv[1], "r");
    if (script_file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    execute_monty_script(script_file);
    
    fclose(script_file);
    free_stack(stack_variable);
    
    return EXIT_SUCCESS;
}
