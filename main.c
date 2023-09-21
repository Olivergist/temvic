#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 * main - Command line Interpreter
 * @argc: represent the number of command
 * @argv: array of string
 * @env: executable file
 * Return: status
 */
int main(int argc, char *argv[], char **env)
{
	int status = 0;
	char *buffer = NULL, *lineptr = NULL;
	char **args;

	while (argc)
	{
		if (isatty(0) == 1)
			write(1, "$ ", 2);

		buffer = read_line(status, lineptr);

		args = tokenize(buffer, " \t\n\r");
		if (args != NULL)
			status = access_command(argv[0], args, env, buffer);
		free(buffer);
		free(args);
	}
	return (status);
}
