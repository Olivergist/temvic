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
	char *buffer = NULL, *lineptr = NULL;
	char **args;

	while (argc)
	{
		if (isatty(0) == 1)
			write(1, "$ ", 2);

		buffer = read_line(lineptr);

		args = tokenize(buffer, " ");
		if (args != NULL)
			access_command(argv[0], args, env, buffer);
		free(buffer);
		free(args);
	}
	return (0);
}
