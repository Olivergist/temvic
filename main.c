#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 *  * main - Command line Interpreter
 *   * Return: 0
 *    */
int main(int argc, char *argv[], char **env)
{
	ssize_t status;
	char *lineptr = NULL;
	size_t n = sizeof(size_t) * 1024;
	char *args[] = {"/bin/ls", NULL};

	while (argc)
	{
		write(1, "$ ", 2);
		status = getline(&lineptr, &n, stdin);
		if (status == -1)
			exit(0);
		lineptr[strlen(lineptr) - 1] = '\0';
		if (execve(lineptr, args, env) == -1)
			perror(argv[0]); 
	}
	free(lineptr);
	return (0);
}
~   
