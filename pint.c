#include "monty.h"
/**
 * 
 * 
 * 
 * 
 */
void m_pint(stack_t **stack, unsigned int line_num)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}