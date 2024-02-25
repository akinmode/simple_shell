#ifndef _PROJECTSHELL_
#define _PROJECTSHELL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* PROTOTYPES */
char *_sh_input(void);
char **_sh_tokens(char *command, char *delim, int arrsize);
void _sh_tokens_count(int *argc, char *command, char *delim);
int _sh_execute(char **argv);
char *_sh_paths(char *paths, char *command);
void free_array(char **arr);
#endif
