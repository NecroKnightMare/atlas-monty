#include "monty.h"
/**
 *p_all -  
 * @stack:
 * @line_num
 * Return:
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *now = *stack;

    (void)line_number;

    while (now)
    {
        printf("%d\n", now->n);
        now = now->next;
    }
}