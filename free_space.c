#include "shell.h"

/**
 * free_env_var - Frees an environment variable.
 * @env_var: The environment variable to free.
 */
void free_env_var(char *env_path)
{
	int i = 4;

	while (i >= 0)
	{
		env_path--;
		i--;
	}
	free(env_path);
}


/**
 * free_tokens - Frees an array of tokens.
 * @tokns: The array of tokens to free.
 * Return: Nothing to return.
 */

void free_tokens(char **tokns)
{
	char **temp = tokns;

	if (tokns)
	{
		while (*tokns)
			free(*tokns++);

		free(temp);
	}
}
