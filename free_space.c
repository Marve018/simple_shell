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
 */
void free_tokens(char **tokens)
{
	int i = 0;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
		tokens[i] = NULL;
	}

	free(tokens);
	tokens = NULL;
}
