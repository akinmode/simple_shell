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

		argc = 0;
		printf("$ ");
		command = _sh_input();
		_sh_tokens_count(&argc, command, delim);
		argv = _sh_tokens(command, delim, argc);
		_sh_execute(argv);
		free_array(argv), free(command);
	} while (1);
	return (0);
}
