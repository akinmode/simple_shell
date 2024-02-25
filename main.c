#include "shell.h"

/**
 * main -  a simple UNIX command interpreter.
 * Return: 0 on success or -1 on failure
*/
int main(void)
{
    while (1)
    {
		char *command = NULL, *delim = " \n", *token;
		char **cmd_array;
		int i = 0, n = 1, p;

        write(1, "#cisfun$ ", 9);
        /*getline(&buffer, &buffer_size, stdin);*/
		command = _sh_input();
		token = strtok(command, delim);
		cmd_array = malloc(sizeof(char *) * 1024);

		while (token)
		{
			cmd_array[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		cmd_array[i] = NULL;

		for (p = 0; p < n; p++)
		{
			printf("%s\n", cmd_array[p]);
		}
		free(command);
		free(cmd_array);
    }
    return (0);
}
