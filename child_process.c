#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int child_process(char *progname, char *command, char **args, char **env)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command, args, env) == -1)
		{
			perror(progname);
			free(command);
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		do {
			waitpid(child, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}
