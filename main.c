#include "shell.h"

/**
 * main - initialize the shell application
 * @argc: integer arguments counter
 * @argv: arguments array
 * Return: 0 on success or -1 on failure
*/

int main(int argc, char **argv)
{
	(void) argv;

	do {
		char *command = NULL, *delim = " \n", *path = NULL;
		char **tokens = NULL;

		argc = 0;

		printf("$ ");
		command = _sh_input();
		_sh_tokens_count(&argc, command, delim);
		tokens = (char **) malloc(sizeof(char *) * (argc));
		if (tokens)
			_sh_tokens(tokens, command, delim);
		path = checkPath(tokens[0]);

		if (path != NULL)
		{
			free(tokens[0]);
			tokens[0] = path;
			_sh_execute(tokens);
		}

		free(command), free(tokens);
	} while (1);
	return (0);
}

/**
 * checkPath - checks for the existing executables
 * @command: first command
 * Return: failure or success
*/

char *checkPath(char *command)
{
	char *allPaths = NULL, *token = NULL, *fullPath = NULL;

	if (access(command, X_OK) != 1)
		return (command);

	allPaths = getenv("PATH");
	token = strtok(allPaths, ":");

	while (token)
	{
		fullPath = malloc((strlen(token) + strlen(command) + 1) * sizeof(char));

		strcpy(fullPath, token);
		strcpy(fullPath, "/");
		strcpy(fullPath, command);

		if (access(fullPath, X_OK) == 1)
			return (fullPath);
		token = strtok(NULL, ":");
		free(fullPath);
	}
	return (NULL);
}
