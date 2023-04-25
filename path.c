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
  * find_path - Verify if a command is found in the system
  * @cmd: The command name to find in the system
  *
  * Return: The path name of the command found or NULL if failed
  */
char *find_path(char *cmd)
{
	
}
