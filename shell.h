#ifndef _SIMPLE_SHELL_HEADER_
#define _SIMPLE_SHELL_HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/sysmacros.h>

void _puts(char *str);
int _putchar(char c);
int take_input(char **str, int if_terminal);
char **create_args(char *string, int *argument_count);
char **realloc_exec_path(char **exec_path, size_t size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *getinput(void);

#endif
