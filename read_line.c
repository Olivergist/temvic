#include "main.h"

char *read_line(char *lineptr)
{
	ssize_t status;
	size_t n = sizeof(size_t) * 1024;

	status = getline(&lineptr, &n, stdin);
	if (status == -1)
	{
		free(lineptr);
		exit(EXIT_SUCCESS);
	}

	lineptr[strlen(lineptr) - 1] = '\0';

	return (lineptr);
}
