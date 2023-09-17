#include "main.h"

void child_process(char *progname, char **args, char **env, char *buffer)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(progname);
			free(buffer);
			free(args);
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		do {
			waitpid(child, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
