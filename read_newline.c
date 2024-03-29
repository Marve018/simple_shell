#include "shell.h"

/**
  * remove_newline - Removes a new line character from string
  * @str: The string
  *
  * Return: The string without a new line character
  */
char *remove_newline(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (str);
}
