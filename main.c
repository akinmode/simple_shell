#include "shell.h"

/**
 * main -  a simple UNIX command interpreter.
 * Return: 0 on success or -1 on failure
*/
int main(int argc, char **argv)
{
    while (1)
    {
		char *command = NULL, *delim = " \n";
		int i = 0;

        write(1, "#cisfun$ ", 9);
		command = _sh_input();
		argv = _sh_tokens(&argc, command, delim);
		
		while (i < argc)
		{
			printf("%s\n", argv[i]);
			i++;
		}
		free(command);
		free(argv);
    }
    return (0);
}
