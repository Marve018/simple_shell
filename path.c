#include "shell.h"

/**
  * concat_path - Concatenate a path name and a program name
  * @pathname: The path name to concatenate with the program name
  * @prgname: The program name to place in the path name
  *
  * Return: The path name concatenated with the program name
  */
char *concat_path(char *pathname, char *prgname)
{
	int plen = 0, prglen = 0, n_size = 0;

	plen = _strlen(pathname);
	prglen = _strlen(prgname);
	n_size = sizeof(char) * (plen + prglen + 2);

	pathname = _realloc(pathname, (plen + 1), n_size);
	if (pathname == NULL)
		return (NULL);
	_strcat(pathname, " /");
	_strcat(pathname, prgname);

	return (pathname);
}

/**
  * find - Verify if a command is found in the system
  * @cmd: The command name to find in the system
  *
  * Return: The path name of the command found or NULL if failed
  */

char *find(char *cmd)
{
	char *env_path = NULL, **p_tokns = NULL;
	int i = 0, num_del = 0;
	struct stat sb;

	if (cmd)
	{
		if (stat(cmd, &sb) != 0 && cmd[0] != '/')
		{
			env_path = _getenv("PATH");
			num_del = count_delims(env_path, ":") + 1;
			p_tokns = tokenize(env_path, ":", num_del);

			while (p_tokns[i])
			{
				p_tokns[i] = concat_path(p_tokns[i], cmd);

				if (stat(p_tokns[i], &sb) == 0)
				{
					free(cmd);
					cmd = _strdup(p_tokns[i]);
					free_env_var(env_path);
					free_tokens(p_tokns);
					return (cmd);
				}

				i++;
			}

			free_env_var(env_path);
			free_tokens(p_tokns);
		}

		if (stat(cmd, &sb) == 0)
			return (cmd);
	}

	free(cmd);
	return (NULL);
}
