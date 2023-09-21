#include "main.h"

/**
 * builtin - Implement exit
 * @args: line argument
 * @env: Environment Variables
 * Return: 1
 */

int builtin(char *progname, char **args, char **env, char *buffer)
{
	int i;
	builtin_t builtins[] =

	{
		{"env", env_builtin}, {NULL, NULL},
	};

	i = 0;
	while (builtins[i].cmd != NULL)
	{
		if (strcmp(args[0], "exit") == 0)
			return (exit_builtin(progname, args, env, buffer));

		if (strcmp(builtins[i].cmd, args[0]) == 0)
			return (builtins[i].func(args, env));
		i++;
	}
	return (1);
}
/**
 * exit_builtin - This help with leaving the array
 * @args: line argument
 * @env: Environment Variables
 * Return: -1
 */
int exit_builtin(char *progname, char **args, char **env, char *buffer)
{
	int i;
	(void)env;

	if (args[1] == NULL)
	{
		free(args);
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	else if (isnumber(args[1]) == 0 && atoi(args[1]) >= 0)
	{
		i = atoi(args[1]);

		free(args);
		free(buffer);
		exit(i);
	}
	else
	{
		write(2, progname, custom_strlen(progname));
		write(2, ": 1: ", 5);
		write(2, args[0], custom_strlen(args[0]));
		write(2, ":Illegal number: ", 17);
		write(2, args[1], custom_strlen(args[1]));
		write(2, "\n", 1);
	}
	return (0);
}

/**
 * env_builtin - implementaion of env
 * @args: arguments listed
 * @env: environment variables
 * Return: 0
 */

int env_builtin(char __attribute__((unused))**args, char **env)
{
	int i = 0;

	if (env == NULL)
		return (1);
	while (env[i] != NULL)
	{
		write(1, env[i], custom_strlen(env[i]) + 1);
		write(1, "\n", 2);
		i++;
	}
	return (0);
}
