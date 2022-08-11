#include "shell.h"

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
 * **realloc_exec_path - reallocates
 * memory to an existing string array
 *
 * @exec_path: the original string array for memory reallocation
 * @size: the original string array size
 * Return: a new resized string array
 */

char **realloc_exec_path(char **exec_path, size_t size)
{
	char **new_exec_path;
	size_t i;

	new_exec_path = malloc((size + 10) * sizeof(char *));

	if (new_exec_path == NULL)
		return (NULL);

	for (i = 0; i < size + 10; i++)
		new_exec_path[i] = exec_path[i];

	free(exec_path);
	return (new_exec_path);
}

/**
 * take_input - waits for the user to enter
 * commands in the program for them to be run
 *
 * @str: a pointer to the string agument passed by user
 * @execuption_path: a triple pointer to the
 * programs execution path
 * @if_terminal: an integer showing if the commands were
 * passed from the terminal
 * @envp: environment variables
 * Return: nothing
 */

void take_input(char **str, char **execuption_path,
	int if_terminal, char **envp)
{

	if (if_terminal)
		_puts("($) ");

	*str = getinput(execuption_path, envp);
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
	char **execution_path;
	char **args;
	int array_size, argument_count, if_terminal, command_count;

	(void)argc;
	(void)command_count;
	array_size = 10;
	argument_count = 0;
	if_terminal = isatty(fileno(stdin));
	command_count = 0;

	envp = create_env(envp);

	execution_path = create_execution_path(&array_size, environ);
	signal(SIGTSTP, SIG_IGN);
	while (1)
	{
		command_count++;
		take_input(&string, execution_path, if_terminal, envp);
		if (string[0] == '\0')
			continue;

		args = create_args(string, &argument_count);

		if (check_run_if_builtin(args, argument_count, string,
			execution_path, envp) == -1)
		{
			if (execute_args(args, execution_path, array_size, envp, argv[0],
						command_count) == 1)
				_puts("yes");
		}
		free(args);
		free(string);
	}
	return (0);
}

