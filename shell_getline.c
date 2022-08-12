#include "shell.h"

/**
 * intlen - Determine Length Of Int
 * @num: Given Int
 * Return: Length Of Int
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * _itoa - Convert Integer To Char
 * @n: Int To Convert
 * Return: Char Pointer
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @shellname: program name
 * @command_count: Simple Shell Count Loop
 * @args: arguments passed to the program
 * @where: where the program was first run
 * Return: Void
 */
void print_error(char *shellname, int command_count, char **args, int where)
{
	char *er;

	_puts_error(shellname);
	_puts_error(": ");
	er = _itoa(command_count);
	_puts_error(er);
	free(er);
	_puts_error(": ");
	if (where == 2)
	{
		perror(args[0]);
	}
	else if (where == 3)
	{
		_puts_error("exit: Illegal number: ");
		_puts_error(args[1]);
		_puts_error("\n");
	}
	else
	{
		_puts_error(args[0]);
		_puts_error(": not found");
		_puts_error("\n");
	}
}

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
 * @status: exit_p status
 * Return: user input
 */
char *getinput(char **execuption_path, char **envp, int *status)
{
	int i, buffsize = 512, rd, space, new_buffsize;
	char c = 0;
	char *buff;

	space = 0;
	buff = malloc(buffsize);
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		if (i == buffsize)
		{
			new_buffsize = buffsize * 2;
			buff = _realloc(buff, buffsize, new_buffsize);
			if (buff == NULL)
				return (NULL);
			buffsize = new_buffsize;
		}
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
			free_buff(execuption_path, envp, buff, status);
		if (_isalpha(c) && !space)
			space = 1;
		buff[i] = c;
	}
	if (!space || buff[0] == '\n')
	{
		free(buff);
		return ("");
	}
	buff[i] = '\0';
	return (buff);
}
