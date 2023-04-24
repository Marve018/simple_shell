#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

/* fun_list */
int _putchar(char c);
int _atoi(char *s);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/* fun_list2 */
int _strncmp(const char *s1, const char *s2, size_t len);
char *_strdup(char *str);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size);

/*tokenize*/
char **tokenize(char *str, char *delim, int len);

/*exec*/
int exec(char *cmd, char **copts);

/*read_newline*/
char *remove_newline(char *str);

/* main */
int count_input(char *str);
#endif
