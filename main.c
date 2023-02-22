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
		argc = 0;

		printf("$ ");
		command = _sh_input();
		_sh_tokens_count(&argc, command, delim);
		tokens = (char **) malloc(sizeof(char *) * (argc));
		if (tokens)
			_sh_tokens(tokens, command, delim);
		printf("%d\n", argc);
		printf("%s\n", argv[0]);

		
		free(command), free(tokens);
	} while (1);
	return (0);
}
