#include "shell.h"

/**
 * bfree - Frees a ptr and NULLs Address
 * @ptr: Address of the ptr to free
 *
 * Return: if freed 1, 0 otherwise.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
