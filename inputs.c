#include "shell.h"

/**
 * _sh_input - gets the command line input
 * Return: 0 on success or -1 on failure
*/
char *_sh_input(void)
{
    char *buffer = NULL;
    size_t buffer_size = 0;

	if (getline(&buffer, &buffer_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("No such file or directory");
			exit(EXIT_FAILURE);
		}
		free(buffer);
	}
	return (buffer);
}
