#include "shell.h"

/**
 * _sh_input - gets the command line input
 * Return: 0 on success or -1 on failure
*/
char *_sh_input(void)
{
	char *command = NULL;
	size_t n;

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
		free(command);
	}
	return (command);
}

/**
 * _sh_tokens_count - counts the possible tokens
 * from the command line input
 * @argc: counnt of tokens from command split
 * @command: input string command
 * @delim: delimiter
 * Return: integer count
*/
void _sh_tokens_count(int *argc, char *command, char *delim)
{
	char *token = NULL, *command_cpy = NULL;

	command_cpy = strdup(command);
	token = strtok(command_cpy, delim);
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
 * @command: input string command
 * @delim: delimiter
 * @arrsize: array size
 * Return: array of token pointers
*/
char **_sh_tokens(char *command, char *delim, int arrsize)
{
	char **arr = NULL, *token = NULL, *argpath = NULL;
	int idx = 0;

	arr = (char **) malloc(sizeof(char *) * (arrsize));
	token = strtok(command, delim);
	while (token)
	{
		arr[idx] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(arr[idx], token);
		token = strtok(NULL, delim);
		idx++;
	}
	arr[idx] = NULL;
	/* Check path for the input command */
	argpath = _sh_paths("PATH", arr[0]);
	if (argpath != NULL)
	{
		arr[0] = argpath;
	}
	return (arr);
}

/**
 * _sh_execute - Executes the command
 * @argv: tokenized array
 * Return: failure or success
*/

int _sh_execute(char **argv)
{
	pid_t apid;

	apid = fork();
	if (apid == -1)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	else if (apid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		wait(0);
	}
	return (0);
}

/**
 * _sh_paths - checks for the existing executables
 * @paths: environment paths
 * @command: first command
 * Return: NULL or Full path of program
*/

char *_sh_paths(char *paths, char *command)
{
	char *token, *delim = ":", *path_cpy;

	if (access(command, X_OK) != -1)
	{
		return (command);
	}
	else
	{
		path_cpy = strdup(getenv(paths));
		token = strtok(path_cpy, delim);
		while (token)
		{
			char *newpath = NULL;

			newpath = malloc(sizeof(char) * (strlen(token) + strlen(command) + 2));
			if (newpath != NULL)
			{
				strcpy(newpath, token);
				strcat(newpath, "/");
				strcat(newpath, command);
				if (access(newpath, F_OK) != -1 && access(newpath, X_OK) != -1)
				{
					return (newpath);
				}
			}
			token = strtok(NULL, delim);
			free(newpath);
		}
		free(path_cpy);
	}
	return (NULL);
}
