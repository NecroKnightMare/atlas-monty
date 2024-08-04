#include "monty.h"
#include <stdio.h>
/**
 * push_it - add to the stack
 * @stack: stack type
 * @line_num: positive number to the stack
 * @arg: 
 * Return: no ret
 */
void m_push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new;
    int result;

    if (!arg || !atoi(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    result = atoi(arg);
    new = malloc(sizeof(stack_t));
    if (!new)
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