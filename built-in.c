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
