#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
/**
 * main - void
 * @argc: argument
 * @argv: filename access
 * Return: 0 if success
 */
int main (int argc, char *argv[])
{
    int line_number = 0;
    char *line = 0;
    FILE *file;

    stack_t *stack = NULL;
    /**read = getline(&line, &len, file);**/


    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /**read = getline(&line, &len, file);**/
    line = malloc(1024);

    while (fgets(line, 1024, file) != NULL)
    {
        line_number++;
    
        char *opcode = strtok(line, "\n\t");
        if (opcode == NULL)
        {
            continue;
        }
        if (strcmp(opcode, "nop") == 0)
        {
            m_nop(&stack, line_number);
        }

        else if (strcmp(opcode, "add") == 0)
        {
            m_add(&stack, line_number);
        }

        else if (strcmp(opcode, "swap") == 0)
        {
            m_swap(&stack, line_number);
        }
          else if (strcmp(opcode, "pop") == 0)
        {
            m_pop(&stack, line_number);
        }
         else if (strcmp(opcode, "pint") == 0)
        {
            m_pint(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }
    free(line);
    fclose(file);
    return (0);
}
