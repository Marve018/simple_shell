#include "shell.h"

/**
 * main - shell entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	char *input = NULL;
	ssize_t input_len = 0;
	size_t input_size;

	(void) ac;
	(void) av;
	while (input_len >= 0)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		input_len = getline(&input, &input_size, stdin);
		if (input_len == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
	}
	free(input);
	return (0);
}
