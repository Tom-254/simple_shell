#include "shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: pointer to the memory previously allocated with a call to
 * malloc: malloc(old_size)
 * @old_size: the size, in bytes, of the allocated space for @ptr
 * @new_size: the new size, in bytes of the new memory block
 *
 * Return: @ptr if @new_size == @old_size, NULL if new_size == 0 &&
 * @ptr != NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ar;
	char *oldar = ptr;
	unsigned int i;

	if (old_size == new_size)
		return (ptr);
	if (ptr == NULL)
	{
		ar = malloc(new_size);
		return (ar);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	ar = malloc(new_size);
	if (ar == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		ar[i] = oldar[i];

	free(oldar);
	return (ar);
}

/**
 * getinput - Read The Input By User From Stdin
 * @execuption_path: a triple pointer to the
 * programs execution path
 * @envp: environment variables
 * Return: user input
 */
char *getinput(char **execuption_path, char **envp)
{
	int i, buffsize = 1024, rd;
	char c = 0;
	char *buff;

	buff = malloc(buffsize);
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			_puts("\n");
			free(execuption_path);
			free_env(envp);
			free(buff);
			exit(EXIT_SUCCESS);
		}

		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
				return (NULL);
		}
	}
	buff[i] = '\0';
	return (buff);
}
