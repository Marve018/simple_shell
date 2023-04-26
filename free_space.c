#include "shell.h"

/**
 * free_env_var - Frees an environment variable.
 * @env_var: The environment variable to free.
 */
void free_env_var(char *env_var)
{
    free(env_var);
}


/**
 * free_tokens - Frees an array of tokens.
 * @tokens: The array of tokens to free.
 */
void free_tokens(char **tokens)
{
    if (tokens == NULL)
        return;

    for (int i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
        tokens[i] = NULL;
    }

    free(tokens);
    tokens = NULL;
}
