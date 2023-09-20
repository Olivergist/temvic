#include "main.h"

/**
 * custom_strlen - Focusing on Custom file
 * @str: the input strings
 * Return: the length
 */

size_t custom_strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')

	{
		length++;
	}

	return (length);

}

