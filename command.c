#include "main.h"

int access_command(char *progname, char **args, char **env, char *buffer)
{
	int i;
	char *path, *_path, *cmd;

	i = builtin(args, env);
	if (i == 0 || i == -1)
		return (i);

	if (access(args[0], X_OK) == 0)
	{
		child_process(progname, args, env, buffer);
		return (0);
	}

	else
	{
		i = 0;
		path = syspath();
		if (path == NULL)
		{
			command_not_found(progname, args);
			free(path);
			return (1);
		}
		_path = malloc(sizeof(char) * 1024);
		_path = strtok(path, ":");
		while (_path != NULL)
		{
			cmd = malloc(sizeof(char) * 1024);
			strcpy(cmd, _path);
			printf("%s\n", cmd);
			strcat(cmd, "/");
			strcat(cmd, args[0]); /* path[i]/<the command> */
			printf("%s\n", cmd);
			if (access(cmd, X_OK) == 0)
			{
				/* simply copy the path[i] into args[0] */
				/* because it will be needed in the child_process function */
				args[0] = cmd;
				free(_path);
				free(path);
				free(cmd);
				child_process(progname, args, env, buffer);
				return (0);
			}
			i++;
			_path = strtok(NULL, ":");
			free(cmd);
		}
		free(_path);
		free(path);
	}
	command_not_found(progname, args);
	return (1);
}


void command_not_found(char *progname, char **args)
{
	write(2, progname, custom_strlen(progname));
	write(2, ": ", 2);
	write(2, "1: ", 4);
	write(2, args[0], custom_strlen(args[0]));
	write(2, ": not found\n", 12);
}
