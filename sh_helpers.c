#include "shell.h"

/**
 * free_array - free allocate dmemory from arrays
 * @arr: allocated array
 * Return: Nothing
*/

void free_array(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
