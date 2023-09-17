#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "main.h"

/**
 * main - Command line Interpreter
 * Return: 0
 */
int main(int argc, char *argv[], char **env)
{
	ssize_t status;
	char *lineptr = NULL;
	size_t n = sizeof(size_t) * 1024;
	char *args[] = {"/bin/ls", NULL};

	while (argc)
	{
		if (isatty(0) == 1)
			write(1, "$ ", 2);
		status = getline(&lineptr, &n, stdin);
		if (status == -1)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		lineptr[strlen(lineptr) - 1] = '\0';

		child_process(argv[0], lineptr, args, env);
	}
	free(lineptr);
	return (0);
}
