#include "shell.h"

/**
 * main -  a simple UNIX command interpreter.
 * Return: 0 on success or -1 on failure
*/
int main(int argc, char **argv)
{
	char *sys;
	sys = argv[0];

    while (1)
    {
		char *command = NULL, *delim = " \n";

        write(1, "#cisfun$ ", 9);
		command = _sh_input(sys);
		argv = _sh_tokens(&argc, command, delim);
		if (_sh_execute(sys, argv) == -1)
		{
			perror(sys);
		}
		free(command);
		free(argv);
    }
    return (0);
}
