#include "main.h"

/**
 * builtin - Implement exit
 * @args: line argument
 * @env: Environment Variables
 * Return: 1
 */

int builtin(char **args, char **env)
{
	int i;
	builtin_t builtins[] =

	{
		{"exit", exit_builtin}, {NULL, NULL},
	};

	i = 0;
	while (builtins[i].cmd != NULL)
	{
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
int exit_builtin(char **args, char **env)
{
	(void)args;
	(void)env;

	return (-1);
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
