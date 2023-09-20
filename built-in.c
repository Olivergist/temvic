#include "main.h"

int builtin(char **args, char **env)
{
	int i;
	builtin_t builtins[] = {
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

int exit_builtin(char **args, char **env)
{
	(void)args;
	(void)env;

	return (-1); /* to detect when exit was entered */
}

int env_builtin(char __attribute__((unused))**args, char **env)
{
	int i = 0;

	if (env == NULL)
		return (1);
	while (env[i] != NULL)
	{
		write(1, env[i], custom_strlen(env[i]));
		i++;
	}
	return (0);
}
