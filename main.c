#include "monty.h"

int main(void)
{
    stack_t *stack = NULL;

    push(&stack, 1, "10");
    push(&stack, 2, "20");
    push(&stack, 3, "30");
    pall(&stack, 4);

    return 0;
}