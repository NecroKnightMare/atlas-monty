#include "monty.h"
/**
 * 
 * 
 * 
 * 
 */
void m_swap(stack_t **stack, unsigned int line_num)
{
    stack_t *one, *two;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }

    one = *stack;
    two = (*stack)->next;

    one->prev = two;
    one->next = two->next;

    if(two->next != NULL)
    {
        two->next->prev = one;
    }

    two->prev = NULL;
    two->next->first;
    *stack = two;
}