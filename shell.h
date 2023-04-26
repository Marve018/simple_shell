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

/* builtin */
int execBuiltInCommands(char **u_tokns, char *line);

/* environ */
char *_getenv(const char *name);
void _print_env(void);

/* path */
char *concat_path(char *pathname, char *prgname);
char *find(char *cmd);

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
int count_delims(char *str, char *delim);

/*read_newline*/
char *remove_newline(char *str);

/* main */
int count_input(char *str);

/* Free space */
void free_tokens(char **tokns);
void free_env_var(char *env_var);

/* Handle_exit */
void _handle_exit(char **u_tokns, char *line);

/* openHelp */
void openHelp(void);

/* Handles Signals */
void signal_handler(int sig_id);
#endif
