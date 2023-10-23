#include "monty.h"

/**
 * usage_error - Prints a usage error message.
 *
 * Return:
 *   - (EXIT_FAILURE) always.
 *
 * Description:
 *   This function is responsible for printing an error message indicating
 *   the correct usage of the Monty Bytecode Interpreter. It returns
 *   (EXIT_FAILURE) to signal an error condition.
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints a malloc error message.
 *
 * Return:
 *   - (EXIT_FAILURE) always.
 *
 * Description:
 *   This function is responsible for printing an error message indicating
 *   that a memory allocation (malloc) has failed. It returns
 *   (EXIT_FAILURE) to indicate a memory allocation error.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Prints a file opening error message with the filename.
 * @filename: Name of the file that failed to open.
 *
 * Return:
 *   - (EXIT_FAILURE) always.
 *
 * Description:
 *   This function is responsible for printing an error message indicating
 *   that the specified file could not be opened. It includes the name of
 *   the file in the error message. It returns (EXIT_FAILURE) to signal
 *   a file opening error.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints an unknown instruction error message.
 * @opcode: Opcode where the error occurred.
 * @line_number: Line number in the Monty bytecodes file where the error
 *		occurred.
 *
 * Return:
 *   - (EXIT_FAILURE) always.
 *
 * Description:
 *   This function is responsible for printing an error message indicating
 *   that an unknown or unrecognized instruction (opcode) was encountered
 *   in the Monty bytecodes file. It includes the opcode and line number
 *   in the error message. It returns (EXIT_FAILURE) to signal an error.
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints an invalid monty_push argument error message.
 * @line_number: Line number in the Monty bytecodes file where the error
 *		occurred.
 *
 * Return:
 *   - (EXIT_FAILURE) always.
 *
 * Description:
 *   This function is responsible for printing an error message indicating
 *   that an invalid argument was provided for the `push` instruction in
 *   the Monty bytecodes file. It includes the line number in the error
 *   message. It returns (EXIT_FAILURE) to indicate an invalid argument error.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
