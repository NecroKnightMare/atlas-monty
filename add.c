#include "monty.h"
/**
 * 
 * 
 * 
 */
void m_add(stack_t **stack, unsigned int line_number)
{
    stack_t *one, *two;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    one = *stack;
    two = (*stack)->next;

    two->n += one->n;
    *stack = two;
    two->prev = NULL;
    free(one);
}