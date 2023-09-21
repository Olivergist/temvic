#include "main.h"

/**
 * access_command - handle the access
 * @progname: handle error message
 * @args: Array of command
 * @env: A string pointer
 * @buffer: A pointer of character
 * Return: 1
 */

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
		path = syspath();

		if (path == NULL)
		{
			command_not_found(progname, args);
			free(path);
			return (1);
		}
		_path = strtok(path, ":");
		i = access_command2(_path, path, progname, args, env, buffer);
		if (i == 0)
			return (0);
		free(path);
	}
	command_not_found(progname, args);
	return (1);
}

/**
 * access_command2 - handle the access
 * @_path: handle _path
 * @path: Also handle path
 * @progname: A string pointer
 * @args: Array of command
 * @env: environment strings
 * @buffer: A pointer of character
 * Return: 1
 */

int access_command2(char *_path, char *path, char *progname, char **args,
		char **env, char *buffer)
{
	char *cmd;

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
		strcat(cmd, args[0]);
		if (access(cmd, X_OK) == 0)
		{
			args[0] = cmd;
			free(path);
			child_process(progname, args, env, cmd, buffer);
			free(cmd);
			return (0);
		}
		_path = strtok(NULL, ":");
		free(cmd);
	}
	return (1);
}

/**
 * command_not_found - Function not to find command
 * @progname: Check error message
 * @args: Array of command line
 */

void command_not_found(char *progname, char **args)

{
	write(2, progname, custom_strlen(progname));
	write(2, ": ", 2);
	write(2, "1: ", 4);
	write(2, args[0], custom_strlen(args[0]));
	write(2, ": not found\n", 12);
}
