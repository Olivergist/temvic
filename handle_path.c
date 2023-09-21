#include "main.h"

/**
 * syspath -  this function splits the path into paths
 * Return: paths
 */


char *syspath(void)
{
	char *_path, *path;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);


	_path = strdup(path);

	return (_path);
}

/**
 * syspaths -  this function splits the path into paths
 * Return: paths
 */

char **syspaths(void)
{
	char **paths;
	char *path;

	path = syspath();
	if (path == NULL)
	{
		free(path);
		return (NULL);
	}

	paths = tokenize(path, ":");

	free(path);
	return (paths);
}
