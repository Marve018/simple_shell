#include "shell.h"

/**
 * exec - Executes a command with options
 * @cmd: The command to execute
 * @copts: The options or flags to the command
 *
 * Return: 0 on success, -1 on error
 */
int exec(char *cmd, char **copts)
{
	int check;
	pid_t pid;

	switch (pid = fork())
	{
		case -1:
			perror("failed fork");
			return (-1);
		case 0:
			execve(cmd, copts, environ);
			break;
		default:
			do {
				 waitpid(pid, &check, WUNTRACED);
			} while (WIFEXITED(check) == 0 && WIFSIGNALED(check) == 0);

	}
	return (0);
}

/**
  * count_delims - Counts delimiters in a string
  * @str: The string that contains the delimiters
  * @delim: The delimiters to will find in the string
  *
  * Return: The number of delimiters in the string
  */
int count_delims(char *str, char *delim)
{
	int cwrd = 0, i, j;

	for (i = 0; delim[i]; i++)
	{
		for (j = 0; str[j]; j++)
		{
			if (str[j] == delim[i])
				cwrd++;
		}
	}
	return (cwrd);
}
