#include "monty.h"

/**
 * pop_error - Prints a "pop" error message for empty stacks.
 * @line_number: Line number in the script where the error occurred.
 *
 * Return:
 *   - (EXIT_FAILURE) always.
 *
 * Description:
 *   This function is responsible for printing an error message indicating
 *   that the "pop" operation cannot be performed on an empty stack. It
 *   includes the line number in the script where the error occurred. It
 *   returns (EXIT_FAILURE) to signal an error condition.
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints a "pint" error message for empty stacks.
 * @line_number: Line number in the Monty bytecodes file where the error
 *		occurred.
 *
 * Return:
 *   - (EXIT_FAILURE) always.
 *
 * Description:
 *   This function is responsible for printing an error message indicating
 *   that the "pint" operation cannot be performed on an empty stack. It
 *   includes the line number in the Monty bytecodes file where the error
 *   occurred. It returns (EXIT_FAILURE) to signal an error condition.
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints error messages for math functions with stacks
 *                     smaller than two nodes.
 * @line_number: Line number in the Monty bytecodes file where the error
 *		occurred.
 * @op: The operation where the error occurred.
 *
 * Return:
 *   - (EXIT_FAILURE) always.
 *
 * Description:
 *   This function is responsible for printing an error message indicating
 *   that certain mathematical operations, represented by `op`, cannot be
 *   performed on a stack or queue with fewer than two nodes. It includes
 *   the line number in the Monty bytecodes file and the specific operation
 *   where the error occurred. It returns (EXIT_FAILURE) to signal an error.
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints a division error message for division by zero.
 * @line_number: Line number in the Monty bytecodes file where the error
 *		occurred.
 *
 * Return:
 *   - (EXIT_FAILURE) always.
 *
 * Description:
 *   This function is responsible for printing an error message indicating
 *   that division by zero is not allowed. It includes the line number in
 *   the Monty bytecodes file where the error occurred. It returns
 *   (EXIT_FAILURE) to signal a division by zero error.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints error messages for "pchar" operation on empty stacks
 *               and non-character values.
 * @line_number: Line number in the Monty bytecodes file where the error
 *		occurred.
 * @message: The corresponding error message to print.
 *
 * Return:
 *   - (EXIT_FAILURE) always.
 *
 * Description:
 *   This function is responsible for printing an error message indicating
 *   that the "pchar" operation cannot be performed on an empty stack or if
 *   the value is not a character. It includes the line number in the Monty
 *   bytecodes file and a specific error message. It returns (EXIT_FAILURE)
 *   to signal an error condition.
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
