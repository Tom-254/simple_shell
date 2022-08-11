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

extern char **environ;

int _strlen(char *s);

int _strcmp(char *s1, char *s2);

char *_strdup(char *str);

char *_strcpy(char *dest, char *src);

char *strcat_dynamic(char *dest, char *path_sep, char *src);

char **realloc_exec_path(char **exec_path, size_t size);

char **create_execution_path(int *size, char **envp);

int check_if_file_exists(const char *filename);

int call_execve(char *program, char **args, char **envp,
	char *shell_name, int command_count);

int execute_args(char **args, char **execution_path, int array_size,
	char **envp, char *shell_name, int command_count);

char **create_args(char *string, int *argument_count);

void take_input(char **str, char **execuption_path,
	int if_terminal, char **envp);
void exit_shell(char **args, char *string, char **execution_path, char **envp);
void _puts(char *str);
int _putchar(char c);
void print_environment(char **envp);
int check_run_if_builtin(char **args, int argument_count, char *string,
	char **execution_path, char **envp);
char **create_env(char **env);
void free_env(char **env);
char *_strstr(char *haystack, char *needle);
char *create_path(char **envp);
char *getinput(char **execuption_path, char **envp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void print_error(char *shellname, int command_count, char **args, int where);
char *_itoa(unsigned int n);
int intlen(int num);
void array_rev(char *arr, int len);

#endif

