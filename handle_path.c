#include "main.h"

char *syspath(void)
{
	char *_path, *path;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	/* create a duplicate of the path */
	/* strdup mallocs the path_dup variable */
	_path = strdup(path);

	return (_path);
}

/**
 * this function splits the path into paths
 * using ':' as the delimiter because the path
 * actually contains a list of paths separated by ':'
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
