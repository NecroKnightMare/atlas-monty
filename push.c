#include "monty.h"
/**
 * push_it - 
 * @stack:
 * @line_num:
 * @arg:
 * Return:
 */
void push_it(stack_t **stack, unsigned int line_num, char *arg)
{
    stack_t *new;
    int result;

    if (!arg || !atoi(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_num);
        exit(EXIT_FAILURE);
    }
    result = atoi(arg);
    new = malloc(sizeof(stack_t));
    if(!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = result;
    new->prev = NULL;
    new->next = *stack;
    if (*stack)
    {
        (*stack)->prev = new;
    }
    *stack = new;
}