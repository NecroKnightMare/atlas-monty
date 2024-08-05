#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <ctype.h>
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
    char *arg = NULL;
    FILE *file;

    stack_t *stack = NULL;


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

    line = malloc(1024);

    while (fgets(line, 1024, file) != NULL)
    {
        line_number++;
    
        char *opcode = strtok(line, "\n\t");
        if (opcode == NULL)
        {
            continue;
        }

        if (strcmp(opcode, "push") == 0)
        {
            /**arg = strtok(NULL, "\t\n");**/
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        
        arg = strtok(NULL, "\t\n");
        
        if (arg == NULL || !isdigit(*arg))
        {
            /**fprintf(stderr, "L%d: usage: push integer\n", line_number);
           **/ exit(EXIT_FAILURE);
        }

        /**n = atoi(arg);**/

        if (strcmp(opcode, "nop") == 0)
        {
            m_nop(&stack, line_number);
            exit(EXIT_FAILURE);
        }

        if (strcmp(opcode, "add") == 0)
        {
            m_add(&stack, line_number);
            fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
            exit(EXIT_FAILURE);
        }

        if (strcmp(opcode, "swap") == 0)
        {
            m_swap(&stack, line_number);
            fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
            exit(EXIT_FAILURE);
        }
        if (strcmp(opcode, "pop") == 0)
        {
            m_pop(&stack, line_number);
            fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
            exit(EXIT_FAILURE);
        }
        if (strcmp(opcode, "pint") == 0)
        {
            m_pint(&stack, line_number);
            fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
            exit(EXIT_FAILURE);
        }
    }
    free(line);
    fclose(file);
    return (0);
}