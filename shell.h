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

#endif
