#include "monty.h"

/**
 * set_op_tok_error - Set an error code in op_toks array.
 * @error_code: Integer error code to store in op_toks.
 * Return: void type return
 */
void set_op_tok_error(int error_code)
{
	int toks_length = 0, i = 0;
	char *exit_code_str = NULL;
	char **new_tokens = NULL;

	toks_length = token_arr_len();
	new_tokens = malloc(sizeof(char *) * (toks_length + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (i < toks_length)
	{
		new_tokens[i] = op_toks[i];
		i++;
	}
	exit_code_str = get_int(error_code);
	if (!exit_code_str)
	{
		free(new_tokens);
		malloc_error();
		return;
	}
	new_tokens[i++] = exit_code_str;
	new_tokens[i] = NULL;
	free(op_toks);
	op_toks = new_tokens;
}
