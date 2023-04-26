#include "shell.h"

/**
  * count_input - Counts the words typed by the user
  * @str: The string that contains the words
  *
  * Return: The number of words found in the string
  */
int count_input(char *str)
{
	int i = 0, cwrd = 0, cnd = 0;
	/* cwrd-word count, cnd-condition */

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			cnd = 0;
		else if (cnd == 0)
		{
			cnd = 1;
			cwrd++;
		}

		i++;
	}

	return (cwrd);
}

/**
 * main - shell entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	char *input = NULL, **u_toks = NULL;
	ssize_t input_len = 0;
	size_t input_size;
	int wrd_len, execflag = 0;

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

		wrd_len = count_input(input);
		if (wrd_len > 0 && input[0] != '\n')
		{
			u_toks = tokenize(input, " \t", wrd_len);
			execflag = execBuiltInCommands(u_toks, input);
			if (!execflag)
			{
				u_toks[0] = find(u_toks[0]);
				if (u_toks[0] && access(u_toks[0], X_OK) == 0)
					exec(u_toks[0], u_toks);
				else
					perror("./hsh");
			}
			free_tokens(u_toks);
		}
	}
	free(input);
	return (0);
}
