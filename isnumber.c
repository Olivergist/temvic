#include "main.h"

int isnumber(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (custom_isdigit(s[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
