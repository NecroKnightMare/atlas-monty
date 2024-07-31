#include "monty.h"
/**
 *p_all -  
 * @stack:
 * @line_num
 * Return:
 */
void p_all(stack_t **stack, unsigned int line_num)
{
    stack_t *now = *stack;

    (void)line_num;

    while (now)
    {
        printf("%d\n", now->n);
        now = now->next;
    }
    return (1);
}