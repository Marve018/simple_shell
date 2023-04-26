#include "shell.h"

/**
 * free_env_var - Frees an environment variable.
 * @env_var: The environment variable to free.
 */
void free_env_var(char *env_var)
{
	int i = 4;

	while (i >= 0)
	{
		env_var--;
		i--;
	}
	free(env_var);
}


/**
 * free_tokens - Frees an array of tokens.
 * @tokens: The array of tokens to free.
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
