#include "shell.h"

/**
 * main - initialize the shell application
 * @argc: integer arguments counter
 * @argv: arguments array
 * Return: 0 on success or -1 on failure
*/

int main(int argc, char **argv)
{
	char *command, *command_cpy, **tokens, *delim = " \n";
	int tokens_c, status;
	pid_t apid;
	(void) argc;

	do {
		command = NULL, command_cpy = NULL, tokens = NULL, tokens_c = 0;

		printf("$ ");
		command = _sh_input();
		command_cpy = strdup(command);
		tokens_c = _sh_tokens_count(command_cpy, delim);
		tokens = (char **) malloc(sizeof(char *) * (tokens_c + 1));
		if (tokens)
			_sh_tokens(tokens, command, delim);
		apid = fork();
		if (apid == -1)
		{
			perror("Error");
			return (1);
		}
		else if (apid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				perror(argv[0]);
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
		free(command), free(command_cpy), free(tokens);
	} while (1);
	return (0);
}

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
			perror("No such file or directory");
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

int _sh_tokens_count(char *command, char *delim)
{
	char *token = NULL;
	int tokens_c = 0;

	token = strtok(command, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		tokens_c++;
	}
	return (tokens_c);
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
