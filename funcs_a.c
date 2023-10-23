#include "monty.h"

/**
 * monty_push - Pushes a value onto a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in a Monty bytecode file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new_node;
	int i;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new_node->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		temp = (*stack)->next;
		new_node->prev = *stack;
		new_node->next = temp;
		if (temp)
		{
			temp->prev = new_node;
		}
		(*stack)->next = new_node;
	}
	else
	{
		temp = *stack;
		while (temp->next)
		{
			temp = temp->next;
		}
		new_node->prev = temp;
		new_node->next = NULL;
		temp->next = new_node;
	}
}

/**
 * monty_pall - Prints the values in a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in a Monty bytecode file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}

/**
 * monty_pint - Prints the top value in a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in a Monty bytecode file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * monty_pop - Removes the top value from a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in a Monty bytecode file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next_node = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	next_node = (*stack)->next->next;
	free((*stack)->next);
	if (next_node)
	{
		next_node->prev = *stack;
	}
	(*stack)->next = next_node;
}

/**
 * monty_swap - Swaps the top two values in a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in a Monty bytecode file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	if (temp->next)
	{
		temp->next->prev = (*stack)->next;
	}
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
