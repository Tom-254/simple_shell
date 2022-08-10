#include "shell.h"

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
