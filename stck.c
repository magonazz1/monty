#include "monty.h"

/**
 * free_stack - Frees a stack_t data structure.
 * @stack: A pointer to the stack_t data structure.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;

	while (*stack)
	{
		current = (*stack)->next;
		free(*stack);
		*stack = current;
	}
}

/**
 * init_stack - Initializes a stack_t data structure with a stack mode.
 * @stack: A pointer to an uninitialized stack_t data structure.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int init_stack(stack_t **stack)
{
	stack_t *new_stack;

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		return (malloc_error());
	}

	new_stack->n = STACK;
	new_stack->prev = NULL;
	new_stack->next = NULL;

	*stack = new_stack;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks the mode of a stack_t data structure.
 * @stack: A pointer to a stack_t data structure.
 *
 * Return: STACK (0) if the stack_t is in stack mode,
 *         QUEUE (1) if it's in queue mode, or 2 if unknown.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
	{
		return (STACK);
	}
	else if (stack->n == QUEUE)
	{
		return (QUEUE);
	}
	return (2);
}
