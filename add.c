#include "monty.h"
/**
 * 
 * 
 * 
 */
void m_add(stack_t **stack, unsigned int line_num)
{
    stack_t *one, *two;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }

    one = *stack;
    two = (*stack)->next;

    two->n += one->n;
    *stack = two;
    two->prev = NULL;
    free(first);
}