#include "monty.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/**
 * main - Entry point for Monty Bytecode Interpreter
 * @argc: The count of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Description:
 * This function serves as the entry point for the Monty Bytecode Interpreter.
 * It takes the count of command-line arguments (argc) and an array of strings
 * (argv) containing the command-line arguments.
 * If the number of arguments is not exactly 2, it returns EXIT_FAILURE and
 * displays a usage error message.
 * It then attempts to open the Monty bytecode file specified in argv[1] for
 * reading. If the file cannot be opened, it returns EXIT_FAILURE and displays
 * an error message indicating the failed file open.
 * If the file is successfully opened, it proceeds to execute the Monty
 * interpreter logic by calling the run_monty function with the opened file.
 * Finally, it closes the opened file and returns the exit code from
 * run_monty, which can be EXIT_SUCCESS or EXIT_FAILURE.
 *
 * Return:
 * - EXIT_SUCCESS on successful execution of the Monty interpreter.
 * - EXIT_FAILURE on errors such as incorrect usage or failed file open.
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int close_code = EXIT_SUCCESS;

	if (argc != 2)
	{
		return (usage_error());
	}
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
	{
		return (f_open_error(argv[1]));
	}
	close_code = run_monty(script_fd);
	fclose(script_fd);
	return (close_code);
}
