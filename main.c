#include "shell.h"

/**
 * main - initialize the shell application
 * @argc: integer arguments counter
 * @argv: arguments array
 * Return: 0 on success or -1 on failure
*/

int main(int argc, char **argv)
{
	do {
		char *command = NULL, *delim = " \n";
		char **tokens = NULL;
		pid_t apid;

		argc = 0;

		printf("$ ");
		command = _sh_input();
		_sh_tokens_count(&argc, command, delim);
		tokens = (char **) malloc(sizeof(char *) * (argc));
		if (tokens)
			_sh_tokens(tokens, command, delim);

		apid = fork();
		if (apid == -1)
		{
			perror("Error");
			return (-1);
		}
		else if (apid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				perror(argv[0]);
				return (-1);
			}
		}
		else
		{
			wait(0);
		}

		free(command), free(tokens);
	} while (1);
	return (0);
}
