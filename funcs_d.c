#include "monty.h"

/* PROTOYTPES USED */
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Rotate the top value of a stack_t linked list to the bottom.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecode file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		return;
	}

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_rotr - Rotate the bottom value of a stack_t linked list to the top.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecode file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		return;
	}

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_stack - Convert a queue to a stack.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecode file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Convert a stack to a queue.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecode file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
