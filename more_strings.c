#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}

/**
 * free - Read The Input By User From Stdin
 * @execuption_path: a triple pointer to the
 * programs execution path
 * @envp: environment variables
 * @buff: string buffer
 * @status: exit_p status
 * Return: user input
 */
void free_buff(char **execuption_path, char **envp,
	char *buff, int status)
{
	free(execuption_path);
	free_env(envp);
	free(buff);
	exit(status);
}
