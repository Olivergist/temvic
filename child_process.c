#include "main.h"
/**
 * child_process - create new process
 * @progname: variable name
 * @args: array of pointers
 * @env: environment variables
 * @cmd: Processing command
 * @buffer: holding specific Data
 */

void child_process(char *progname, char **args, char **env, char *cmd,
		char *buffer)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(progname);
			free(cmd);
			free(buffer);
			free(args);
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		do

		{
			waitpid(child, &status, WUNTRACED);
		}

		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
