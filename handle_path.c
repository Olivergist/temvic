#include "main.h"

char *syspath(void)
{
	char *path_dup;
	char *path = getenv("PATH");

	/* create a duplicate of the path */
	/* strdup mallocs the path_dup variable */
	path_dup = strdup(path);

	return (path_dup);
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
	paths = tokenize(path, ":");

	free(path);
	return (paths);
}
