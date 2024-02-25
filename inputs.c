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

/**
 * _sh_tokens_count - counts the possible tokens
 * from the command line input and returns
 * an array of arguments
 * @argc: count of tokens from command split
 * @command: input string command
 * @delim: delimiter
 * Return: integer count
*/
 char **_sh_tokens(int *argc, char *command, char *delim)
{
    char **cmd_array, *token;
    int i = 0;
    (*argc) = 0;
    
    cmd_array = malloc(sizeof(char *) * 1024);

    token = strtok(command, delim);
    while (token)
    {
        (*argc)++;
        cmd_array[i] = token;
        token = strtok(NULL, delim);
        i++;
    }
    cmd_array[i] = NULL;
    return (cmd_array);
}
