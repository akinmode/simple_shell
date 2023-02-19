#ifndef _PROJECTSHELL_
#define _PROJECTSHELL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* PROTOTYPES */
char *_sh_input(void);
char **_sh_tokens(char *command);
int _sh_tokens_count(char *command,  char *delim);
#endif
