#include "shell.h"

/**
 * main -  a simple UNIX command interpreter
 * and entry point
 * Return: Always 0.
*/
int main(void)
{
	int status;

    while (1)
    {
		char *command = NULL;

        write(STDOUT_FILENO, "$ ", 2);
		command = _sh_input();
		
		if (command == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}
		else
		{
			status = _sh_execute(command);
			printf("%d\n", status);
		}
		free(command);
    }
    return (0);
}
