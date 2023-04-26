#include "shell.h"

/**
 * _handle_exit - Handles the exit command
 * @u_tokns: An array of strings representing the user input tokens
 * @line: The user input string
 *
 * Return: None
 */
void _handle_exit(char **u_tokns, char *line)
{
	int status;

	if (u_tokns[1] == NULL) /* No argument provided */
	{
		frees_tokens(u_tokns);
		free(line);
		exit(EXIT_SUCCESS);
	}

	status = _atoi(u_tokns[1]); /* Convert argument to integer */

	if (status == 0 && _strcmp(u_tokns[1], "0") != 0) /* Invalid argument */
	{
		_puts("exit: Illegal number: ");
		_puts(u_tokns[1]);
		_puts("\n");
		exit(EXIT_FAILURE);
	}

	frees_tokens(u_tokns);
	free(line);
	exit(status); /* Exit with provided status */
}
