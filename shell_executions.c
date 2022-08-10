#include "shell.h"

/**
 * create_execution_path - creates
 * the programs executables locations path
 *
 * @size: the initial size of the execution path to be created
 * Return: the path array of strings
 * @envp: the environment variables
 */

char **create_execution_path(int *size, char **envp)
{
	char *path_string;
	char *token;
	int i;
	char **execution_path;

	execution_path = malloc(*size * sizeof(char *));

	if (execution_path == NULL)
	{
		perror("Error");
		exit(1);
	}

	i = 0;

	path_string = create_path(envp);

	token = strtok(path_string, ":");
	execution_path[i] = token;
	i++;
	while (token != NULL)
	{
		if (i == *size)
		{
			execution_path = realloc_exec_path(execution_path, *size);
		}
		token = strtok(NULL, ":");
		execution_path[i] = token;
		i++;
	}
	*size = i - 1;

	return (execution_path);
}

/**
 * check_if_file_exists - check if a specific
 * file path passed into it actually exists
 *
 * @filename: the file name to be checked
 * Return: an integer 1 if file exists 0 if it doesn't
 */

int check_if_file_exists(const char *filename)
{
	struct stat buffer;
	int exist;

	exist = stat(filename, &buffer);
	if (exist == 0)
		return (1);
	else
		return (0);
}

/**
 * call_execve - calls the execve function
 * to execute the program passed
 *
 * @program: the name of the executable to be called and executed
 * @args: an array of strings containing arguments
 * passsed by the user of the program
 * @envp: the environment variables
 * @shell_name: the name of the shell
 * @command_count: count of commands passed
 * into the shell program since its initialization
 * Return: an integer depending on the
 * exit code of the executed command showing error or not
 */

int call_execve(char *program, char **args, char **envp,
		char *shell_name, int command_count)
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
		if (execve(program, args, envp) == -1)
		{
			dprintf(STDERR_FILENO, "%s: %d: ", shell_name, command_count);
			perror(args[0]);
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
 * call_execve - calls the execve function to
 * execute the program passed
 *
 * @args: an array of strings containing
 * arguments passsed by the user of the program
 * @execution_path: an array of strings containing
 * the potential directory location for the
 * command to be executed
 * @array_size: size of the array of arguments
 * @envp: the environment variables
 * @shell_name: the name of the shell
 * @command_count: count of commands passed into
 * the shell program since its initialization
 * Return: returns the command executed exit status
 */

int execute_args(char **args, char **execution_path, int array_size,
		char **envp, char *shell_name, int command_count)
{
	char *exec_p;
	int i;
	int status;

	status = 1;

	if (args[0][0] == '/')
	{
		if (check_if_file_exists(args[0]))
		{
			status = call_execve(args[0], args, envp,
				shell_name, command_count);

			status = 0;
		}
	}
	else
	{
		for (i = 0; i < array_size; i++)
		{
			exec_p = strcat_dynamic(execution_path[i], "/", args[0]);
			if (check_if_file_exists(exec_p))
			{
				status = call_execve(exec_p, args, envp,
						shell_name, command_count);
				status = 0;
				free(exec_p);
				break;
			}
			free(exec_p);
		}
	}
	return (status);
}

/**
 * **create_args - separates the arguments
 * passed into an array of arguments
 *
 * @string: the single string of arguments passed
 * @argument_count: pointer to the count of
 * arguments passed into the program
 * Return: a string array of arguments passed
 */

char **create_args(char *string, int *argument_count)
{
	char *token;
	char **args;
	int i;
	int size;

	size = 10;
	i = 0;

	args = malloc(size * sizeof(char *));

	if (args == NULL)
	{
		perror("Error:");
		return (NULL);
	}

	token = strtok(string, "\n \t\r");
	args[i] = token;
	i++;
	while (token != NULL)
	{
		if (i == size)
		{
			args = realloc_exec_path(args, size);
		}
		token = strtok(NULL, "\n \t\r");
		args[i] = token;
		i++;
	}

	(*argument_count) = i - 1;

	args[i] = NULL;
	return (args);
}
