#include "main.h"

/**
 * read_line - fgets functions to file
 * @lineptr: Pointer to a character
 * @status: Checking for status
 * Return: lineptr
 */

char *read_line(int status, char *lineptr)
{
	ssize_t flag;
	size_t n = sizeof(size_t) * 1024;

	flag = getline(&lineptr, &n, stdin);
	if (flag == -1)
	{
		free(lineptr);
		if (isatty(0) == 0)
			exit(status);
		exit(EXIT_SUCCESS);
	}

	lineptr[custom_strlen(lineptr) - 1] = '\0';

	return (lineptr);
}
