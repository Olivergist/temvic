#include "main.h"

/**
 * tokenize - breaking of Strings
 * @buffer: optimize data transfer
 * @delim: sequence of Character
 * Return: args
 */

char **tokenize(char *buffer, char *delim)
{
	char *token = NULL;
	char **args = NULL;
	int i, buffer_size = 1024;


	args = malloc(sizeof(char *) * buffer_size);
	if (args == NULL)
	{
		perror("Unable to allocate memory");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delim);
	if (token == NULL)
	{
		free(token);
		free(args);
		return (NULL);
	}
	for (i = 0; token != NULL; i++)
	{
		if (i >= buffer_size)
		{
			buffer_size += 1024;
			/* realloc */
			args = realloc(args, sizeof(char *) * buffer_size);
			if (args == NULL)
			{
				perror("Unable to reallocate memory");
				free(args);
				free(token);
				exit(EXIT_FAILURE);
			}
		}
		/* terminate with null */
		args[i] = token;
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	free(token);
	return (args);
}
