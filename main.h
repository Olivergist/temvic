#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void child_process(char *progname, char **args, char **env, char *buffer);
char **tokenize(char *lineptr, char *delim);
char *read_line(int status, char *lineptr);
char *syspath(void);
char **syspaths(void);
int access_command(char *progname, char **args, char **env, char *buffer);
size_t custom_strlen(const char *str);
void command_not_found(char *progname, char **args);
#endif	/* MAIN_H */
