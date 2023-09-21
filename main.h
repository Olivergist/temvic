#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stddef.h>

/**
 * struct builtin_s - structure for builtins
 *
 * @cmd: the command
 * @func: the function to execute for @cmd
 */

typedef struct builtin_s
{
	char *cmd;
	int (*func)(char **, char **);
} builtin_t;

void child_process(char *progname, char **args, char **env, char *cmd,
		char *buffer);
char **tokenize(char *lineptr, char *delim);
char *read_line(int status, char *lineptr);
char *syspath(void);
char **syspaths(void);
int access_command(char *progname, char **args, char **env, char *buffer);
int access_command2(char *_path, char *path, char *progname, char **args,
		char **env, char *buffer);
size_t custom_strlen(const char *str);
void command_not_found(char *progname, char **args);
int exit_builtin(char **args, char **env);
int builtin(char **args, char **env);
int env_builtin(char **args, char **env);

#endif  /* MAIN_H */
