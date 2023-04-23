#include "shell.h"

/**
  * _strncmp - Compares at most the first n bytes of str1 and str2
  * @s1: The first string
  * @s2: The second string
  * @len: The limit bytes of comparison
  *
  * Return: int value
  */
int _strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned int pos = 0;
	int diff = 0;

	while (pos < len)
	{
		if (s1[pos] == s2[pos])
		{
			pos++;
			continue;
		}
		else
		{
			diff = s1[pos] - s2[pos];
			break;
		}

		pos++;
	}

	return (diff);
}

/**
  * _strdup - Duplicate a string
  * @str: the string to duplicate
  *
  * Return: the string duplicated
  */
char *_strdup(char *str)
{
	int idx = 0, len = 1;
	char *dup_str;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup_str = malloc((sizeof(char) * len) + 1);
	if (dup_str == NULL)
		return (NULL);

	while (idx < len)
	{
		dup_str[idx] = str[idx];
		idx++;
	}

	dup_str[idx] = '\0';
	return (dup_str);
}

/**
  * _puts - Prints a string
  * @str: The string to print
  *
  * Return: NULL
  */
void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}

	_putchar('\n');
}

/**
  *_realloc - Reallocates memory that was previously allocated
  * @ptr: The pointer previously allocated
  * @o_size: The old size of the pointer
  * @n_size: The new size of the new pointer
  *
  * Return: A new pointer to the memory block allocated with the new size
  */
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	char *nptr;
	unsigned int i;

	if (n_size == o_size)
		return (ptr);

	if (ptr == NULL)
	{
		nptr = malloc(n_size);

		if (nptr == NULL)
			return (NULL);

		return (nptr);
	}
	else
	{
		if (n_size == 0)
		{
			free(ptr);
			return (NULL);
		}
	}

	nptr = malloc(n_size);

	if (nptr == NULL)
		return (NULL);

	for (i = 0; i < o_size && i < n_size; i++)
	{
		nptr[i] = ((char *) ptr)[i];
	}

	free(ptr);
	return (nptr);
