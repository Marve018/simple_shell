#include "shell.h"

/**
 * _putchar - prints a character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _atoi - Converts a string to an integer.
  * @s: The pointer to convert
  *
  * Return: An integer
  */
int _atoi(char *s)
{
	int min = 1, si = 0, i = 0;
	unsigned int n = 0;

	while (s[i])
	{
		if (s[i] == '-')
			min *= -1;

		while (s[i] >= '0' && s[i] <= '9')
		{
			si = 1;
			n = (n * 10) + (s[i] - '0');
			i++;
		}

		if (si == 1)
			break;

		i++;
	}

	n *= min;
	return (n);
}
/**
  * _strcat - Concatenates two strings
  * @dest: The destination string
  * @src: The source string
  *
  * Return: A pointer to the resulting string dest
  */
char *_strcat(char *dest, char *src)
{
	int len = 0, i = 0;

	while (dest[len])
		len++;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len] = src[i];
		len++;
	}

	dest[len] = '\0';
	return (dest);
}

/**
  * _strlen - Counts the length of a string
  * @s: The string to counts
  *
  * Return: The length of a string
  */
int _strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i])
		i++;

	return (i);
}

/**
 * _strcmp - compares two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
