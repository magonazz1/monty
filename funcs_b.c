#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - Adds the second value from the top of the stack_t linked list
 *             to the top value and stores the result in the second value node.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Description: Removes the top value from the stack.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - Subtracts the top value from the second value of the stack_t
 *		linked list and stores the result in the second value node.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Description: Removes the top value from the stack.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - Divides the second value from the top of the stack_t linked list
 *             by the top value and stores the result in the second value node.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Description: Removes the top value from the stack. Handles division by zero.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - Multiplies the second value from the top of the stack_t
 *		linked list by the top value and stores the result in
 *		the second value node.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Description: Removes the top value from the stack.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - Computes the modulus of the second value from the top
 *		of the stack_t linked list by the top value and stores
 *		the result in the second value node.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Description: Removes the top value from the stack. Handles division by zero.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
