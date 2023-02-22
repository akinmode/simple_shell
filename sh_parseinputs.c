#include "shell.h"
/**
 * _sh_input - gets the command line input
 * Return: 0 on success or -1 on failure
*/

char *_sh_input(void)
{
	char *command = NULL;
	size_t n = 0;

	if (getline(&command, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("command not found");
			exit(EXIT_FAILURE);
		}
	}
	return (command);
}

/**
 * _sh_tokens_count - counts the possible tokens
 * from the command line input
 * @command: input string command
 * @delim: delimiter
 * Return: integer count
*/

void _sh_tokens_count(int *argc, char *command, char *delim)
{
	char *token = NULL, *command_cpy = NULL;

	command_cpy = strdup(command);
	token = strtok(command, delim);
	(*argc)++;
	while (token)
	{
		token = strtok(NULL, delim);
		(*argc)++;
	}
	free(command_cpy);
}

/**
 * _sh_tokens - generates tokens
 * from the command line input
 * @arr: array of pointer of tokens to e generated
 * @command: input string command
 * @delim: delimiter
 * Return: array of token pointers
*/
void _sh_tokens(char *arr[], char *command, char *delim)
{
	char *token;
	int ind = 0;

	token = strtok(command, delim);
	while (token)
	{
		arr[ind] = token;
		token = strtok(NULL, delim);
		ind++;
	}
	arr[ind] = NULL;
}
