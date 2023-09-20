#include "main.h"

int access_command(char *progname, char **args, char **env, char *buffer)
{
	int i;
	char **path;

	if (access(args[0], X_OK) == 0)
	{
		child_process(progname, args, env, buffer);
		return (0);
	}

	else
	{
		i = 0;
		path = syspaths();
		while (path[i] != NULL)
		{
			printf("%s\n", path[i]);
			strcat(path[i], args[0]); /* path[i]/<the command> */
			if (access(path[i], X_OK) == 0)
			{
				/* simply copy the path[i] into args[0] */
				/* because it will be needed in the child_process function */
				strcpy(args[0], path[i]);
				printf("%s\n", args[0]);
				free(path);
				child_process(progname, args, env, buffer);
				return (0);
			}
			i++;
		}
		free(path);
	}
	perror(progname);
	return (1);
}
