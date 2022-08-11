#include "shell.h"


/**
 * free_env - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */
void free_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}

/**
 * exit_shell - call to exit the shell program
 * @args: an array of strings containing
 * arguments passsed by the user of the program
 * @string: untokenized string passed by user
 * @execution_path: an array of strings containing
 * the potential directory location for the
 * command to be executed
 * @envp: environment variables
 * Return: nothing
 */

void exit_shell(char **args, char *string, char **execution_path, char **envp)
{
	free(args);
	free(string);
	free(execution_path);
	free_env(envp);
	exit(EXIT_SUCCESS);
}

/**
 * create_env - make the shell environment from the environment passed to main
 * @env: environment passed to main
 *
 * Return: pointer to the new environment
 */
char **create_env(char **env)
{
	char **newenv = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * (i + 1));
	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		newenv[i] = _strdup(env[i]);
	newenv[i] = NULL;
	return (newenv);
}

/**
 * print_environment - returns the length of a string
 *
 * @envp: environment_varibles
 *
 * Return: nothing
 */

void print_environment(char **envp)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		_puts(envp[i]);
		_puts("\n");
		i++;
	}
}

/**
 * check_run_if_builtin - returns the length of a string
 * @args: an array of strings containing
 * arguments passsed by the user of the program
 * @argument_count: number of agurments since initial run
 * @string: the untokenized userinput string
 * @execution_path: an array of strings containing
 * the potential directory location for the
 * @envp: environment_varibles
 *
 * Return: nothing
 */

int check_run_if_builtin(char **args, int argument_count, char *string,
	char **execution_path, char **envp)
{
	int built_in_total, built_in_to_exec, i;
	char *built_ins[2];

	built_ins[0] = "env";
	built_ins[1] = "exit";

	(void)argument_count;

	built_in_total = 2;
	built_in_to_exec = -1;

	for (i = 0; i < built_in_total; i++)
	{
		if (_strcmp(args[0], built_ins[i]) == 0)
		{
			built_in_to_exec = i;
			break;
		}
	}

	switch (built_in_to_exec)
	{
	case 0:
		print_environment(envp);
		break;
	case 1:
		exit_shell(args, string, execution_path, envp);
		break;
	default:
		built_in_to_exec = -1;
		break;
	}

	return (built_in_to_exec);
}
