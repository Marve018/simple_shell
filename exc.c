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
	pid_t pid, w;

	switch (pid = fork())
	{
		case -1:
			perror("failed fork");
			return (-1);
		case 0:
			if (execve(cmd, copts, NULL) == -1)
			{
				/* perror("failed execve");*/
				exit(EXIT_FAILURE);
			}
			break;
		default:
			while (1)
			{
				w = waitpid(pid, &check, WUNTRACED);
				if (w == -1)
					return (-1);
				else if (WIFEXITED(check) || WIFSIGNALED(check))
					break;
			}
			break;
	}
	return (0);
}
