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
	return (write(1, &c, 1));
}


/**
 * _puts - prints out a string, followed by a new line
 *
 * @str: the string to be printed out
 *
 * Return: the string
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * take_input - waits for the user to enter
 * commands in the program for them to be run
 *
 * @str: a pointer to the string agument passed by user
 * Return: an integer
 * @if_terminal: an integer showing if the commands were
 * passed from the terminal
 */

int take_input(char **str, int if_terminal)
{
	size_t size;
	ssize_t chars_read;

	size = 0;

	if (if_terminal)
		_puts("($) ");

	chars_read = getline(str, &size, stdin);

	if (chars_read < 0)
	{
		_puts("\n");
		free(*(str));
		exit(0);
	}

	if (chars_read != 1)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

/**
 * main - acts as the entry point for the shell program
 * @argc: number of arguments passed on initial shell program run
 * @argv: an array of strings containing arguments
 * passsed on initial run of the the program
 * @envp: the environment variables
 * Return: an integer
 */

int main(int argc, char *argv[], char *envp[])
{
	char *string;
	int if_terminal;

	(void)argc;
	(void)argv;
	(void)envp;

	if_terminal = isatty(fileno(stdin));

	signal(SIGTSTP, SIG_IGN);
	while (1)
	{
		if (take_input(&string, if_terminal))
			continue;
	}

	return (0);
}
