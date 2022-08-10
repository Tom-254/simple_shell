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
 * call_execve - calls the execve function
 * to execute the program passed
 *
 * @program: the name of the executable to be called and executed
 * @args: argument passed;
 * Return: an integer depending on the
 * exit code of the executed command showing error or not
 */

int call_execve(char *program, char **args)
{
	pid_t process_id;
	int wait_status;
	int status_code;

	status_code = 0;

	process_id = fork();

	if (process_id == -1)
	{
		perror("Error");
		return (1);
	}

	if (process_id == 0)
	{
		if (execve(program, args, NULL) == -1)
		{
			perror(program);
			exit(2);
		}
	}
	else
	{
		wait(&wait_status);

		if (WIFEXITED(wait_status))
		{
			status_code = WEXITSTATUS(wait_status);
		}
	}

	return (status_code);
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
	int if_terminal, argument_count;
	char **args;


	(void)argc;
	(void)argv;
	(void)envp;

	if_terminal = isatty(fileno(stdin));
	argument_count = 0;

	signal(SIGTSTP, SIG_IGN);
	while (1)
	{
		if (if_terminal)
		{
			_puts("($) ");
		}
		string = getinput();
		if (string[0] == '\0')
			continue;

		args = create_args(string, &argument_count);

		call_execve(args[0], args);
	}
	_puts("\n");
	free(args);
	free(string);
	return (0);
}
