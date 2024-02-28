#ifndef _PROJECTSHELL_
#define _PROJECTSHELL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* PROTOTYPES */
char *_sh_input();
char **_sh_tokens(int *argc, char *command, char *delim);
int _sh_execute(char *shell, int *argc, char *command);

#endif
