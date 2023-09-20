#include "main.h"

int access_command(char *progname, char **args, char **env, char *buffer)
{
	int i;
	char *path, *_path, *cmd;

	i = builtin(args, env);
	if (i == 0)
		return (i);
	else if (i == -1)
	{
		free(args);
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	if (access(args[0], X_OK) == 0)
	{
		cmd = malloc(sizeof(char));
		child_process(progname, args, env, cmd, buffer);
		free(cmd);
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
		_path = strtok(path, ":");
		while (_path != NULL)
		{
			cmd = calloc(sizeof(char), 1024);
			if (cmd == NULL)
			{
				write(1, "Unable to allocate memory\n", 26);
				free(args);
				free(buffer);
				exit(EXIT_FAILURE);
			}

			strcpy(cmd, _path);
			strcat(cmd, "/");
			strcat(cmd, args[0]); /* path[i]/<the command> */
			if (access(cmd, X_OK) == 0)
			{
				/* simply copy the path[i] into args[0] */
				/* because it will be needed in the child_process function */
				args[0] = cmd;
				free(path);
				child_process(progname, args, env, cmd, buffer);
				free(cmd);
				return (0);
			}
			i++;
			_path = strtok(NULL, ":");
			free(cmd);
		}
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
