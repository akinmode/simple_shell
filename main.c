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
