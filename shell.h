#ifndef _PROJECTSHELL_
#define _PROJECTSHELL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* PROTOTYPES */
char *_sh_input(void);
void _sh_tokens(char *arr[], char *command, char *delim);
void _sh_tokens_count(int *argc, char *command, char *delim);
#endif
