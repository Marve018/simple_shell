#include "shell.h"

/**
 * tokenize - Extract tokens from string
 * @str: The string to tokenize
 * @delim: The delimiter of tokenization
 * @len: Tokens number
 *
 * Return: An array of tokens of the string
 */
char **tokenize(char *str, char *delim, int len)
{
	char **tokens = NULL, *token = NULL, *tmp = NULL;
	int tok_count = 0;

	tokens = malloc(sizeof(char *) * (len + 1));
	if (!tokens)
		return (NULL);

	str = remove_newline(str);
	tmp = _strdup(str);

	token = strtok(tmp, delim);

	while (token)
	{
		tokens[tok_count] = _strdup(token);
		token = strtok(NULL, delim);
		tok_count++;
	}
	tokens[tok_count] = NULL;

	free(tmp);
	return (tokens);
}
