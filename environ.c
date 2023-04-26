#include "shell.h"

/**
  * _getenv - Gets environment variable
  * @name: The variable to find in the system environment
  *
  * Return: The content of the environment variable
  */
char *_getenv(const char *name)
{
	char *e_var = NULL;
	int i = 0;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], name, _strlen(name)) == 0)
		{
			e_var = _strdup(environ[i]);
			while (*e_var != '=')
				e_var++;
			++e_var;
			return (e_var);
		}
		i++;
	}
	return (NULL);
}

/**
  * _print_env - Prints the environment builtin
  *
  * Return: void
  */
void _print_env(void)
{
	int i = 0, j = 0;

	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}
		if (j != 0)
			_putchar('\n');
		i++;
	}
}
