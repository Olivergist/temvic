#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - Command line Interpreter
 * Return: 0
 */
int main(int argc, char *argv[], char **env)
{
	ssize_t status;
	int i;
	char *lineptr = NULL;
	size_t n = sizeof(size_t) * 1024;
	char *args[] = {"/bin/ls", NULL};
	pid_t child_process;

	while (argc)
	{
		write(1, "$ ", 2);
		status = getline(&lineptr, &n, stdin);
		if (status == -1)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		lineptr[strlen(lineptr) - 1] = '\0';

		child_process = fork();
		if (child_process == 0)
		{
			if (execve(lineptr, args, env) == -1)
			{
				perror(argv[0]);
				free(lineptr);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			do {
				waitpid(child_process, &i, WUNTRACED);
			} while (!WIFEXITED(i) && !WIFSIGNALED(i));
		}
	}
	free(lineptr);
	return (0);
}
